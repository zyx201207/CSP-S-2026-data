#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int n;
int a[200010];
char c[200010],x;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n;
	int s=0;
	int l=a[1],r=a[n];
	while(i<j){
		x=c[i];
		if(l<=r){
			r-=l;
			if(c[i]!=c[j]){
				s+=l;
				i++;
				l=a[i];
			}else{
				i++;
				l=a[i];
			}
			
		}else{
			l-=r;
			if(c[i]!=c[j]){
				s+=r;
				j--;
				r=a[j];
			}else{
				j--;
				r=a[j];
			}
			
		}
//		cout<<i<<" "<<l<<"  "<<j<<" "<<r<<endl;
	}
	cout<<s;
	return 0;
}

