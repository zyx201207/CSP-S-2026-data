#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[500005],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]<=d){
						if((x[j]-x[i])/d==1&&(x[j]-x[i]+1)/d==2){
						ans++;
					}
				}
			
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
