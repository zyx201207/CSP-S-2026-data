//t2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w[550000],k[550];
struct ss{
	ll v,w;
};
vector<ss> a[550];
vector<ss> b[550000];
ll dis[600][600];
int c,n,m,d,q;
int get_1(){
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=(1ll<<50)-1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=0;k<=j;k++){
				if(k!=j){
					dis[b[i][j].v][b[i][k].v]=dis[b[i][k].v][b[i][j].v]=min(dis[b[i][j].v][b[i][k].v],b[i][j].w+b[i][k].w);
				}
				else dis[b[i][j].v][b[i][k].v]=0;
			}
		}
	}
	/*for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<dis[i][j]<<"  ";
		}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j;k++){
				if(j!=k)
				dis[k][j]=dis[j][k]=min(dis[j][k],dis[i][k]+dis[j][i]);
			}
		}
	}
	//for(ll i=1;i<=n;i++){
		//for(ll j=1;j<=n;j++){
			//cout<<dis[i][j]<<"  ";
		//}
	//}
	return 0;
}
ll get(ll x,ll y){
	ll minn=(1ll<<50)-1;
	for(int j=0;j<b[x].size();j++){
		for(int k=0;k<b[y].size();k++){
			minn=min(minn,dis[b[x][j].v][b[y][k].v]+b[y][k].w+b[x][j].w);
		}
	}
	//cout<<w[x]<<" "<<w[y]<<"\n";
	return minn+w[x]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",k+i);
		for(int j=1;j<=k[i];j++){
			ll v,w;
			scanf("%lld%lld",&v,&w);
			ss k;
			k.v=v;
			k.w=w;
			a[i].push_back(k);
			k.v=i;
			k.w=w;
			b[v].push_back(k);
			
		}
	}
	//cout<<1;
	/*cout<<c<<n<<m<<d<<q;
	for(ll i=1;i<=m;i++){
		cout<<w[i];
	}
	for(ll i=1;i<=n;i++){
		cout<<"\n"<<k[i]<<":";
		for(ll j=0;j<k[i];j++){
			cout<<a[i][j].v<<a[i][j].w<<" ";
			//cout<<b[i][j].v<<b[i][j].w<<" ";
		}
	}for(ll i=1;i<=m;i++){
		cout<<"\n"<<i<<":";
		for(ll j=0;j<b[i].size();j++){
			//cout<<a[i][j].v<<a[i][j].w<<" ";
			cout<<b[i][j].v<<b[i][j].w<<" ";
		}
	}*/
	get_1();//subway to subway;
	for(ll i=1;i<=q;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",get(x,y));
	}
	return 0;
}/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
