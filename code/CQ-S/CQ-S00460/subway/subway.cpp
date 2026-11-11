#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5;
const int M=505;
const int K=25;
int opt,tot,ans;
int n,m,k,q,x,y;
int a[N],b[M],head[N];
int c[M][N],t[M][N],dis[1005][1005];
bool flag[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q; 
struct node{
	int x,y,z;
}nex[N<<1];
void add(int x,int y,int z){
	tot++;
	nex[tot].x=y;
	nex[tot].y=head[x];
	nex[tot].z=z;
	head[x]=tot;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>opt>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=b[i];j++)
			cin>>c[i][j]>>t[i][j];
	}
//	if(7<=opt&&opt<=11){
		for(int i=1;i<=n;i++)
			if(b[i]==2){
				add(c[i][1],c[i][2],t[i][1]+t[i][2]);
				add(c[i][2],c[i][1],t[i][1]+t[i][2]);
			}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(i!=j)
					dis[i][j]=LONG_LONG_MAX;
		for(int i=1;i<=m;i++){
			Q.push(make_pair(0,i));
			while(!Q.empty()){
				pair<int,int> p=Q.top();
				Q.pop();
				x=p.first;
				y=p.second;
				if(flag[y])
					continue;
				flag[y]=true;
				for(int i=head[y];i;i=nex[i].y){
					int w=nex[i].x;
					if(dis[i][w]>x+nex[i].z){
						dis[i][w]=x+nex[i].z;
						Q.push(make_pair(dis[i][w],w));
					}
				}
			}
		}
		while(q--){
			cin>>x>>y;
			cout<<dis[x][y]<<"\n"; 
		}
//	}
	return 0;
}
