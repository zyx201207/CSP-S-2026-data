#include<bits/stdc++.h>
using namespace std;
int c,t;
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	long long n=0,d=0,x[1000],p[1000][1000],m=0;ans=0;
	while(t--){
		m=0;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			x[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				p[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
				
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					p[i][j]=1;
					p[j][i]=1;
					
				}
			/*for(int u=1;u<=n;u++){
					cout<<'\n';
			for(int o=1;o<=n;o++){
				cout<<p[u][o]<<' ';}}*/
				
				
					for(int k=1;k<j;k++){
						//cout<<p[i][k]<<' '<<p[k][j]<<' ';
						if(p[i][k]==1&&p[k][j]==1){
							
						m++;
					} 
				}
			
			if(m==2) ans++;
		}
		}
		cout<<ans<<'\n';
	}
	

	return 0;
}
