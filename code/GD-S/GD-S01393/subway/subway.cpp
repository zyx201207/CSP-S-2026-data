#include<bits/stdc++.h>
#define int long long
using namespace std;
int  c,n,m,d,q,w[50001];
int f[1001][1001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=8){
		for(int i=1;i<=m;i++)cin>>w[i];
		int sumk=0;
		memset(f,-1,sizeof(f));
		for(int j=1;j<=n;j++){
			int k;
			cin>>k;
			for(int i=1;i<=k;i++){
				int x,w;
				cin>>x>>w;
//				cout<<x<<"<->"<<m+sumk+i<<":"<<w<<endl;
				f[x][m+sumk+i]=f[m+sumk+i][x]=w;
				if(i>1){
					f[m+sumk+i-1][m+sumk+i]=f[m+sumk+i][m+sumk+i-1]=0;
//					cout<<m+sumk+i-1<<"->"<<m+sumk+i<<endl;
				}
			}sumk+=k;
		}
		for(int k=1;k<=sumk+m;k++){
			for(int i=1;i<=sumk+m;i++){
				for(int j=1;j<=sumk+m;j++){
					if(i==j||j==k||i==k)continue;
					if(f[i][k]!=-1&&f[k][j]!=-1&&(f[i][j]==-1||f[i][j]>f[i][k]+f[k][j])){
//						cout<<i<<"->"<<j<<"mid "<<k<<":"<<f[i][j]<<","<<f[i][k]+f[k][j]<<"="<<f[i][k]<<"+"<<f[k][j]<<endl;
						f[i][j]=f[i][k]+f[k][j];
					}
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<f[x][y]+w[x]+w[y]<<endl;
		}
	}
}
