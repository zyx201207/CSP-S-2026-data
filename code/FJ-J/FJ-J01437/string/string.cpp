#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int c=0;
	char x='#';
}a[N],b[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>b[i].c>>b[i].x;
		if(b[i].x==b[l].x)b[i].x='#',b[l].c+=b[i].c,b[i].c=0;
		else l=i;
	}
	int d=0;
	for(int i=1;i<=n;i++){
		if(b[i].x!='#'){
			a[++d]=b[i];
		}
	}
	int ans=0;
	for(int l=1,r=d;l<r;){
		if(a[l].x==a[r].x){
			if(a[l].c==a[r].c){
				l++,r--;
				continue;
			}
			if(a[l].c>a[r].c){
				a[l].c-=a[r].c,r--;
				continue;
			}
			if(a[l].c<a[r].c){
				a[r].c-=a[l].c,l++;
				continue;
			}
		}
		if(a[l].c>a[r].c){
			ans+=a[r].c;
			a[l].c-=a[r].c,r--;
			continue;
		}
		if(a[l].c==a[r].c){
			ans+=a[r].c;
			l++,r--;
			continue;
		}
		if(a[l].c<a[r].c){
			ans+=a[l].c;
			a[r].c-=a[l].c,l++;
			continue;
		}
	}
	cout<<ans<<"\n";
 } 
 /*
 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
 */
