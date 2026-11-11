#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define LL long long
using namespace std;
const int N=1e3+10;
const int Inf=0x3f3f3f3f;
LL c,n,m,d,q,k,x,tx,y,ty;
vector<pair<LL,LL>> a[N];
LL edge[N][N],t[N][N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}memset(edge,Inf,sizeof(edge));
//	if(c==7||c==8||c==9||c==10||c==11){
		for(int i=1;i<=n;i++){
			cin>>k;
			if(k==2){
				cin>>x>>tx>>y>>ty;
				t[i][x]=tx;
				t[i][y]=ty;
				for(int k=0;k<a[x].size();k++){
					edge[y][a[x][k].first]=min(edge[y][a[x][k].first],tx+t[a[x][k].second][k]);
				}
				a[x].push_back({y,i});
				a[y].push_back({x,i});	
			}else{
				while(k--)cin>>x>>tx; 
			}
		}for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
				}
			}
		}for(int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<edge[x][y]+w[x]+w[y]<<'\n';
		}
//	}
	
	return 0;
}

