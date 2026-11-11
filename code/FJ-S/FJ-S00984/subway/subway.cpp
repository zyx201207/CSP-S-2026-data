#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int t;
}a[505][25];
int w[500005];
int l[500005][505];
int e[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i][0].id;
		for(int j=1;j<=a[i][0].id;j++) cin>>a[i][j].id>>a[i][j].t;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=0x3f3f3f3f;
	for(int i=1;i<=n;i++) e[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i][0].id;j++){
			if(l[a[i][j].id][0]==0) l[a[i][j].id][1]=i,l[a[i][j].id][0]=1;
			else{
				for(int k=1;k<=l[a[i][j].id][0];k++){
					int n2=l[a[i][j].id][k];
					int idx=1;
					for(;idx<=a[n2][0].id;idx++) if(a[n2][idx].id==a[i][j].id) break;
					e[i][n2]=min(a[i][j].t+a[n2][idx].t,e[i][n2]);
					e[n2][i]=e[i][n2];

				}
				l[a[i][j].id][l[a[i][j].id][0]+1]=i,l[a[i][j].id][0]++;
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
				e[u][v]=min(e[u][k]+e[k][v],e[u][v]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f;
		for(int u=1;u<=l[x][0];u++){
			for(int v=1;v<=l[y][0];v++){
				int idx1=1,idx2=1;
				for(;idx1<=a[l[x][u]][0].id;idx1++) if(a[l[x][u]][idx1].id==x) break;
				for(;idx2<=a[l[y][v]][0].id;idx2++) if(a[l[y][v]][idx2].id==y) break;
				ans=min(ans,a[l[x][u]][idx1].t+e[l[x][u]][l[y][v]]+a[l[y][v]][idx2].t);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
//¸ÅÂÊµÃ·Ö 
