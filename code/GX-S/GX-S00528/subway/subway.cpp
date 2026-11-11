#include <bits/stdc++.h>
const int inf=2147483647,maxn=600;
using namespace std;
int c,n,m,d,q,w[maxn],l,a;
struct Node{int fa,t;}node;
vector<Node> getfa[maxn];
struct Q{int x,y;}qu[maxn];
int f[maxn][maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){cin>>l;
        node.fa=i;
        for(int j=1;j<=l;j++){
            cin>>a>>node.t;
            getfa[a].push_back(node);
        }
	}
	for(int i=1;i<=q;i++)cin>>qu[i].x>>qu[i].y;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)f[i][j]=inf;
	}
	for(int i=1;i<=m;i++){
            int h=getfa[i].size();
        for(int j=0;j<h;j++){
            for(int k=0;k<h;k++){
                if(getfa[i][j].fa==getfa[i][k].fa)continue;
                f[getfa[i][j].fa][getfa[i][k].fa]=min(f[getfa[i][j].fa][getfa[i][k].fa],getfa[i][j].t+getfa[i][k].t);
            }
        }
	}
	for(int i=1;i<=n;i++){f[i][i]=0;}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
	}
	for(int i=1;i<=q;i++){
        int ans=inf;
        int h1=getfa[qu[i].x].size();
        int h2=getfa[qu[i].y].size();
        if(qu[i].x==qu[i].y){cout<<ans<<endl;continue;}
        for(int j=0;j<h1;j++){
            for(int k=0;k<h2;k++){
                ans=min(ans,f[getfa[qu[i].x][j].fa][getfa[qu[i].y][k].fa]+getfa[qu[i].y][k].t+getfa[qu[i].x][j].t);
            }ans+=w[qu[i].x]+w[qu[i].y];
        }cout<<ans<<endl;
	}
}
