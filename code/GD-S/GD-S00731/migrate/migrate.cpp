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

const int dtl=4046404640464046;
struct line{int to,nxt;}r[12500001];
int c,T,n,d,x[2000001],mx[2000001],cnt[2000001],fmx[2000002],w[2000001],sum[2000002];
int head[5001],cntt,dis[5001],fas[5001],ans;
mt19937 rd(time(0));
int rng(int l,int r){uniform_int_distribution<int>x(l,r);return x(rd);}
void add(int u,int v){r[++cntt]={v,head[u]};head[u]=cntt;}
void bfs(int fr){
	queue<int>q;
	q.push(fr);
	for(int i=1;i<=n;i++)dis[i]=dtl,fas[i]=0;
	fas[fr]=1;
	dis[fr]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=r[i].nxt){
			int v=r[i].to;
			if(dis[u]+1>dis[v])continue;
			if(dis[u]+1==dis[v]){
				fas[v]+=fas[u];
			}else{//dis[u]+1<dis[v]
				dis[v]=dis[u]+1;
				fas[v]=fas[u];
				q.push(v);
			}
		}
	}
	for(int i=fr+1;i<=n;i++)ans+=fas[i]==2; 
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
//	freopen("migrate4.in","r",stdin);
//	freopen("migrate3.out","w",stdout); 
	cin>>c>>T;
	for(int iiii=1;iiii<=T;iiii++){
		cin>>n>>d;
//		cerr<<n<<" "<<d<<"\n";
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			mx[i]=mx[i-1];
			while(mx[i]<n&&x[mx[i]+1]-x[i]<=d)mx[i]++;
		}
		for(int i=n;i>=1;i--){
			fmx[i]=fmx[i+1];
			while(fmx[i]>1&&x[i]-x[fmx[i]-1]<=d)fmx[i]--;
		}
		ans=0;
		bool fg=true;
		for(int i=2;i<=n;i++)if(x[i]-x[i-1]!=x[2]-x[1])fg=false;
		if(n<=5000){
			for(int i=1;i<=n;i++)head[i]=0;
			cntt=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=mx[i];j++){
					add(i,j);
				}
			}
			for(int i=n;i>=1;i--){
				bfs(i);
			}
			cout<<ans<<"\n";
		}else if(fg){
			for(int i=1;i<=n;i++){
				if(mx[i]-2<i||mx[mx[i]-1]<=mx[i])continue;
				ans+=mx[mx[i]-1]-mx[mx[i]-2];
			}
			cout<<ans<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	akioi;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
