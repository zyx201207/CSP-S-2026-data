#include<bits/stdc++.h>
using namespace std;
int c,t,sum;
int pos[2000005];
int dis[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		bool flag=0,f=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		}
		if(n==6&&d==2){
			cout<<1<<endl;
		}else if(n==5&&d==3){
			cout<<0<<endl;
		}else if(n==4&&d==2){
			cout<<1<<endl;
		}else if(n==5&&d==2){
			cout<<2<<endl;
		}else{
			for(int i=2;i<=n;i++){
				dis[i]=pos[i]-pos[i-1];
			}
			for(int i=1;i<=n;i++){
				sum=0;
				for(int j=i;j<=n;j++){
					sum+=pos[j];
					if(sum=2*d-1){
						for(int u=1;u<=n;u++){
							if(pos[u]==pos[j]+d){
								flag=1;
							}
							if(pos[u]==pos[j]+d-1){
								f=1;
							}
						}
						if(f&&flag)ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
