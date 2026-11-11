//贵阳一中 王怀威 GZ-S00249
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[5005];
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int num=0,Min=0,ans=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				Min=-99999999; num=0;
				for(int k=i+1;k<j;k++){
					Min=max(Min,max(x[k]-x[i],x[j]-x[k]));
					if(Min==x[k]-x[i]||Min==x[j]-x[k]) num++; }
				if(num==2) ans++;
			}            
		}
		cout<<ans<<"\n";
	}
	return 0;
}