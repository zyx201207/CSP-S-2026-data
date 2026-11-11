#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define u first
#define v second
#define fo(i,x,y) for(int i=(x);i<=(y);i++)
#define fr(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
const int N=2e6+5,M=2.5e7+5;
int e[M][2],l[N],d1[N],d2[N],d3[N],b[N][3],n;
ll x[N];
void ad(int x,int y){
	e[++l[0]][0]=y;
	e[l[0]][1]=l[x];
	l[x]=l[0];
}
void bfs(int s){
	fr(i,n,1)
		d1[i]=d2[i]=d3[i]=b[i][0]=b[i][1]=b[i][2]=1e9;
	queue<pr>d;
	d.push({s,0});
	b[s][0]=0;
	while(d.size()){
		while(d.size()&&b[d.front().u][d.front().v]>=d3[d.front().u])
			d.pop();
		if(!d.size())
			break;
		pr x=d.front();
		d.pop();
		int v=b[x.u][x.v];
		if(v<d1[x.u]){
			d3[x.u]=d2[x.u];
			d2[x.u]=d1[x.u];
			d1[x.u]=v++;
		}
		else if(v<d2[x.u]){
			d3[x.u]=d2[x.u];
			d2[x.u]=v++;
		}
		else
			d3[x.u]=v++;
		b[x.u][x.v]=1e9;
		for(int i=l[x.u];i;i=e[i][1])
			if(v<d3[e[i][0]]){
				int j=0;
				while(j<3&&v>=b[e[i][0]][j])
					j++;
				if(j==3)
					continue;
				if(b[e[i][0]][j]==1e9)
					d.push({e[i][0],j});
				b[e[i][0]][j]=v;
			}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	ll d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		fill(l,l+1+n,0);
		fo(i,1,n){
			cin>>x[i];
			fr(j,i-1,1){
				if(x[i]-x[j]>d)
					break;
				ad(i,j);
				ad(j,i);
			}
		}
		ll s=0;
		fo(i,2,n){
			bfs(i);
			fr(j,i-1,1)
				s+=d1[j]==d2[j]&&d2[j]<d3[j];
		}
		cout<<s<<'\n';
	}
	return 0;
}
