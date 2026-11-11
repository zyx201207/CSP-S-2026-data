#\
i\
n\
c\
l\
u\
d\
e\
 \
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
#define int long long
using namespace std;

const int dtl=1e18+249;
struct line{int to,nxt,len;}r[1000001];
int c,n,m,d,Q,k[501],w[500001],dis[501][501];
int cntt,head[600001];
void add(int u,int v,int w){r[++cntt]={v,head[u],w};head[u]=cntt;}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway6.in","r",stdin);
//	freopen("subway6.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			add(a,m+i,t),add(m+i,a,t);
		}
	}
	
	memset(dis,0x3f,sizeof(dis));
	
	for(int i=1;i<=n;i++)dis[i][i]=0;
	
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=r[j].nxt){
			for(int l=r[j].nxt;l;l=r[l].nxt){
				int v1=r[j].to-m;
				int v2=r[l].to-m;
				int ads=r[j].len+r[l].len;
				dis[v1][v2]=min(dis[v1][v2],ads);
				dis[v2][v1]=min(dis[v2][v1],ads);
//				cerr<<"v1:"<<v1<<" v2:"<<v2<<" ads:"<<ads<<" "<<dis[v1][v2]<<"\n";
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				dis[j][l]=min(dis[j][l],dis[j][i]+dis[i][l]);
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				dis[j][l]=min(dis[j][l],dis[j][i]+dis[i][l]);
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			for(int l=1;l<=n;l++){
				dis[j][l]=min(dis[j][l],dis[j][i]+dis[i][l]);
			}
		}
	}
	
	for(int ii=1;ii<=Q;ii++){
		int x,y;cin>>x>>y;
		//x ne y
		int ans=dtl;
		for(int i=head[x];i;i=r[i].nxt){
			for(int j=head[y];j;j=r[j].nxt){
				int v1=r[i].to-m;
				int v2=r[j].to-m;
				int ads=r[i].len+r[j].len;
				ans=min(ans,dis[v1][v2]+ads);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	akioi;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
