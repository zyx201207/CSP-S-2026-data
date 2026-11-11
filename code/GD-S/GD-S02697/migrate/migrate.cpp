#include<bits/stdc++.h>
using namespace std;
int a[2000005],dis[300][300],num[300][300];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(dis,0x7f,sizeof(dis));
		memset(num,0,sizeof(num));
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				dis[i][j]=dis[j][i]=abs(a[i]-a[j]);
				num[i][j]=num[j][i]=1;
				if(dis[i][j]>d){
					dis[i][j]=dis[j][i]=0x7f7f7f7f;
					num[i][j]=num[j][i]=0;
					break;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						if(dis[i][j]==0x7f7f7f7f){
							num[i][j]++;
						}
						dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
					}else if(dis[i][k]+dis[k][j]==dis[i][j]){
						num[i][j]++;
						cout<<i<<','<<j<<':'<<num[i][j]<<'\n';
						if(num[i][j]==2){
							cout<<i<<','<<j<<'\n';
							ans++;
						}else if(num[i][j]>2){
							cout<<'-'<<i<<','<<j<<'\n';
							ans--;
						}
					}
				}
			}
		}
		cout<<ans-1<<'\n';
	}
	return 24-24;
}
