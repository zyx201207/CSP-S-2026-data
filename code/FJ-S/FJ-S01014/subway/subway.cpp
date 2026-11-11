#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int w[N];
struct node{
	int pre,to,len;
}a[N];
int p[N];
int k=0;
void add(int x,int y,int l){
	a[++k].pre=p[x];
	a[k].to=y;
	a[k].len=l;
	p[x]=k;
}
int dd[25];
int t[25];
int dis[N];
int f[N];
void dj(int x){
	priority_queue < pair<int,int >,vector< pair<int,int > > , greater<pair<int,int >> >qq;
	qq.push({0,x});
	dis[x]=0;
	while(!qq.empty()){
		int h=qq.top().second;
		qq.pop();
		for(int i=p[h];i;i=a[i].pre){
			int to=a[i].to;
			if(f[to])continue;
			f[to]=1;
			if(dis[to]>dis[h]+a[i].len){
				dis[to]=dis[h]+a[i].len;
				qq.push({dis[to],to});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>dd[j]>>t[j];
		}
		for(int j=1;j<=kk;j++){
			for(int oo=j+1;oo<=kk;oo++){
				add(dd[j],dd[oo],t[oo]+t[j]);
				add(dd[oo],dd[j],t[j]+t[oo]);
			}
		}
	}
	while(q--){
		for(int i=1;i<=m;i++){
			dis[i]=0x3f3f3f3f;
			f[i]=0;
		}
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans=ans+w[x]+w[y];
		dj(x);
		ans+=dis[y];
		cout<<ans<<"\n";
	}
	return 0;
}
