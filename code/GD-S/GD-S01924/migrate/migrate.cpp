#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[5002][5002];
int c[5002][5002];
void oneT(){
	memset(dis,0x3f,sizeof dis);
	memset(c,0,sizeof c);
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)dis[i][i]=0,c[i][i]=1;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=d){
				dis[i][j]=1;
				c[i][j]=1;
			}else break;
		}
		for(int j=i-1;j>=1;j--){
			for(int k=i-1;k>j;k--){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					c[i][j]=c[i][k]*c[k][j];
				}else if(dis[i][k]+dis[k][j]==dis[i][j]){
					c[i][j]+=c[i][k]*c[k][j];
				}
			}
		}
		for(int j=1;j<i;j++)if(c[i][j]==2)ans++;
	}
	cout<<ans<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dis[i][j]==0x3f3f3f3f3f3f3f3fLL)cout<<"inf ";
//			else cout<<dis[i][j]<<' ';
//			cout<<c[i][j]<<"   ";
//		}
//		cout<<endl;
//	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int CCC,T;
	cin>>CCC>>T;
	while(T--){
		oneT();
	}
	return 0;
} 
