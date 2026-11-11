#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+100;
int c,t;
int a[N];
int s[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1&&a[i]-a[i-1]>d){
				continue;
			}	
			if(i>1){
				int k=i-1;
				while(k--){
					if(k==0)break;
					s[++cnt]=a[i]-a[k];
				}
			}
		}int ans=0;
		for(int i=0;i<=cnt;i++){
			if(s[i]%d==d-1&&s[i]>d)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
