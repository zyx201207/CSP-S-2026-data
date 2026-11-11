#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001];
struct node{
	long long mi;
	int num=0;
}f[1050][1050];
void floyd(){
	//cout<<n;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<k<<" "<<i<<" "<<j<<endl;
				//if(i==1&&j==4&&k==2)cout<<f[1][4].mi<<" "<<f[1][2].mi+f[2][4].mi<<endl;
				if(f[i][k].mi+f[j][k].mi<f[i][j].mi){
					f[i][j].mi=f[j][i].mi=f[i][k].mi+f[j][k].mi;
					f[i][j].num=f[j][i].num=f[i][k].num*f[k][j].num;
				}else if(f[i][k].mi+f[j][k].mi==f[i][j].mi&&k!=i&&k!=j)f[i][j].num++;
			}
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j].mi=1e18;
				f[i][j].num=1;
			}
		}
		for(int i=1;i<=n;i++){
			f[i][i].mi=0;
			f[i][i].num=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d)break;
				else {
					f[i][j].mi=f[j][i].mi=1;
				}
			}
		}
		int ans=0;
		floyd();
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(f[i][j].num==2)ans++;
		cout<<ans<<endl;
	}
	return 0;
} 
