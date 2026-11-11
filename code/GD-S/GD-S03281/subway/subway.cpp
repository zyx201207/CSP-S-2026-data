#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,int>
#define v first
#define u second
#define fo(i,x,y) for(int i=(x);i<=(y);i++)
#define fr(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
const int L1=505,L2=3,N=5e5+5,M=1e6+5,K=2e4+L1;
int w[N],e[M][3],l[N],m,k,cnt;
ll dis1[L1][K],dis2[L2][N];
pr h[M];
void ad(int x,int y,int z){
	e[++l[0]][0]=y;
	e[l[0]][1]=z;
	e[l[0]][2]=l[x];
	l[x]=l[0];
}
void push(pr x){
	int t=++cnt;
	h[t]=x;
	while(t>1&&h[t].v<h[t>>1].v){
		swap(h[t],h[t>>1]);
		t>>=1;
	}
}
void de(){
	h[1]=h[cnt--];
	int x=1;
	while(x<<1<=cnt){
		int y=x<<1;
		y+=y<cnt&&h[y+1].v<h[y].v;
		if(h[x].v<=h[y].v)
			break;
		swap(h[x],h[y]);
		x=y;
	}
}
void dij1(int s){
	fill(dis1[s]+1,dis1[s]+1+k,1e18);
	cnt=0;
	push({0,s+m});
	fo(i,1,k){
		while(cnt&&h[1].v>=dis1[s][h[1].u])
			de();
		if(!cnt)
			break;
		dis1[s][h[1].u]=h[1].v;
		for(int j=l[h[1].u];j;j=e[j][2])
			if(h[1].v+e[j][1]<dis1[s][e[j][0]])
				push({h[1].v+e[j][1],e[j][0]});
	}
}
void dij2(int s){
	fill(dis2[s]+1,dis2[s]+1+k,1e18);
	cnt=0;
	push({0,s+m});
	fo(i,1,k){
		while(cnt&&h[1].v>=dis2[s][h[1].u])
			de();
		if(!cnt)
			break;
		dis2[s][h[1].u]=h[1].v;
		for(int j=l[h[1].u];j;j=e[j][2])
			if(h[1].v+e[j][1]<dis2[s][e[j][0]])
				push({h[1].v+e[j][1],e[j][0]});
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,n,d,q,a,x,y;
	cin>>c>>n>>m>>d>>q;
	fo(i,1,m)
		cin>>w[i];
	fo(i,1,n){
		cin>>k;
		fo(j,1,k){
			cin>>a>>x;
			ad(a,i+m,x);
			ad(i+m,a,x);
		}
	}
	k=m+n;
	fo(i,1,n)
		if(n>2)
			dij1(i);
		else
			dij2(i);
	while(q--){
		cin>>x>>y;
		ll ans=1e18;
		for(int i=l[x];i;i=e[i][2])
			ans=min(ans,e[i][1]+(n>2?dis1[e[i][0]-m][y]:dis2[e[i][0]-m][y]));
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
