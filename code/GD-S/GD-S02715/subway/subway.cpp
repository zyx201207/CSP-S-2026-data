#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5e5+10;
//priority_queue<greater<int>> q;
int cc,n,m,d,q;
int w[N];
int he[N],ne[N],to[N],c[N],id;
void add(int x,int y,int z){
	id++,to[id]=y,ne[id]=he[x],he[x]=id,c[id]=z;
}
ll cnt,dd,dd1;
ll ans=0;
int xx;
int a[N];
int b[N];
int x1,y1;
ll vis[N];
int cc1[40][100010];
int cc2[100010][40];
map<int ,int>mp;
void dfs(int id1,int num1){
	if(num1>=vis[id1]) return ;
	vis[id1]=num1;
	for(int u=he[id1];u!=0;u=ne[u]){
		dfs(to[u],num1+c[u]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(int yy=1;yy<=n;yy++){
		xx=yy+m;
		scanf("%d",&a[0]);
		for(int i=1;i<=a[0];i++){
			scanf("%d%lld",&a[i],&dd);
			add(xx,a[i],dd);
			add(a[i],xx,dd);
		}
	}
	
	while(q--){
		scanf("%d%d",&x1,&y1);
		for(int i=1;i<=n+m+5;i++){
			vis[i]=100000000;
		}
		
		ans=b[x1]+b[y1];
		dfs(x1,0);
		ans+=vis[y1];
		printf("%lld\n",ans);
	}
	return 0; 
}

