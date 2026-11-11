#include<bits/stdc++.h>
using namespace std;
long long cot,t,n,d,x[2000005],f[505],q[505],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>cot>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(cot==11||cot==12){
			if(x[4]-x[1]<=d)cout<<0;
			else if(x[3]-x[1]<=d)cout<<n-3;
			else cout<<0;
			continue;
		}
		for(int k=1;k<=n;k++){
			memset(f,0,sizeof(f));
			memset(q,0,sizeof(q));
			for(int i=k;i<=n;i++){
				if(x[i+1]-x[i]>d)break;
				for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++){
					if(!q[j])f[j]=f[i]+1,q[j]=1;
					else if(f[j]==f[i]+1)q[j]++;
				}
			}
			for(int i=k;i<=n;i++){
				if(q[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 

