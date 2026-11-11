#include<bits/stdc++.h>
using namespace std;
int c,t,dis[5003][5003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,f=0,sum=0;
		cin>>n>>d;
		int a[n+5];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sum=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=sum){
				f=1;
				break;
			}			
		}
		if(!f){
				cout<<(n-1)/d<<endl;
				continue;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				memset(dis,0,sizeof(dis));
				queue<int> q;
				q.push(i);
				dis[i][1]=1;
				while(q.empty()){
					int x=q.front();
					q.pop();
					for(int j=i+1;j<=n;j++){
						if(abs(a[j]-a[i])<=d){
							for(int k=2;k<=n;k++){
								dis[j][k]=dis[x][k-1]+1;
							}
							q.push(j);
						}
						else{
							break;
						}
					}
				}
				for(int j=1;j<=n;j++){
					for(int k=2;k<=n;k++){
						if(dis[j][k]==2){
							cout<<i<<" "<<j<<" "<<k<<endl;
							ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
