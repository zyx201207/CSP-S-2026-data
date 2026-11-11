#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int> a[505];
vector<int> t[505];
int dis[405][405];
int g[405][405];
void floyed(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(dis[i][k]<=1e8&&dis[k][j]<=1e8){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
			dis[i][j]=min(dis[i][j],dis[j][i]);
			dis[j][i]=min(dis[i][j],dis[j][i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway2.in","r",stdin);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].push_back(x);
		t[i].push_back(x);
		for(int j=1;j<=a[i][0];j++){
			int y,z;
			cin>>y>>z;
			a[i].push_back(y);
			t[i].push_back(z);
		}
	}
	if(c<=8){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i][0];j++){
				for(int k=1;k<=a[i][0];k++){
					g[a[i][j]][a[i][k]]=i;
					dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
				}	
			}
		}		
		floyed();
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<(long long)(dis[x][y]+w[x]+w[y])<<endl;
		}
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
//			}
//		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}
//32?
