#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct zf{
	int a,b;
}a[N];
int n,x;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		a[i].a=x; a[i].b=c;
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l].b==a[r].b){
			if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				r--;
			}
			else if(a[l].a<a[r].a){
				a[r].a-=a[l].a;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				ans+=a[r].a;
				r--;
			}
			else if(a[l].a<a[r].a){
				a[r].a-=a[l].a;
				ans+=a[l].a;
				l++;
			}
			else{
				ans+=a[l].a;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 

