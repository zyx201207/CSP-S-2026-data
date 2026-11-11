#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+5;
ll ans,c,t,n,d;
ll zb[maxn],cnt[maxn],zd[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>zb[i];
		zd[1]=0;
		for(int i=1;i<=d;i++)zd[i]=1;
		for(int i=d+1;i<=2*d+1;i++)zd[i]=2;
		for(int i=d*2+1;i<=n;i++){
				ll minl=0x7fffffff;
				ll now=0;
				for(int j=i-1;j>=i-d;j--){
					for(int k=j-1;k>=i-2*d&&k>0;k--){
						if(zd[j]+zd[k]<minl)minl=zd[j]+zd[k],now=1;
						if(zd[j]+zd[k]==minl)now++;
					}
					}
					zd[i]=minl+1;
					if(now==2)ans++;
				}
				cout<<ans<<'\n';
			}
			return 0;

	}
	
	

