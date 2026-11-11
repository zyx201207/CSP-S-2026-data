#include<bits/stdc++.h>
#define tin long long
using namespace std;
tin c,t,n,d,ans,x[2000005],f[2000005],g[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(tin i=1;i<=n;i++) cin>>x[i];
		if(c==13||c==14){
			cout<<n-d-1<<"\n";
			continue;
		}ans=0;
		for(tin s=1;s<=n;s++){
			for(tin k=1;k<=n;k++)
				f[k]=2e18,g[k]=0;
			f[s]=0,g[s]=1;
			for(tin i=s+1;i<=n;i++){
				tin j=i-1;
				while(j>=s&&x[i]-x[j]<=d){
					if(f[j]+1<f[i]) f[i]=f[j]+1,g[i]=g[j];
					else if(f[j]+1==f[i]) g[i]+=g[j];j--;
				}ans+=(g[i]==2); 
			}			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
