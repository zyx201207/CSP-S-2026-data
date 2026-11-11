#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=500005;
int c,n,m,d,q,k[505],tsub[maxn];
ll dijkstra[505][505];
int cross[505][505];
bool bee[505][505];
struct Node{
	vector<int> a,t;
	int l=0;
}sd[maxn];
void dijk(int u){
	queue<int> q;
	bool been[501]={false};
	q.push(u);
	while(!q.empty()){
		int recent=q.front();
		been[recent]=true;
		for(int i=1;i<=m;i++){
			if(bee[recent][i]){
				if(dijkstra[u][i]>dijkstra[u][recent]+dijkstra[recent][i]){
					cross[u][i]=cross[recent][i];
				}
			}
			if(!been[i]&&bee[recent][i]){
				q.push(i);
				dijkstra[u][i]=(dijkstra[u][i]<dijkstra[u][recent]+dijkstra[recent][i])?dijkstra[u][i]:(dijkstra[u][recent]+dijkstra[recent][i]);
			}
		}
		q.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>tsub[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dijkstra[i][j]=2305842009213693592;
			if(i==j)dijkstra[i][j]=0;
		} 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll xa,xt;
			cin>>xa>>xt;
			(sd[xa].a).push_back(i);
			(sd[xa].t).push_back(xt);
			sd[xa].l++;
			for(int w=0;w<sd[xa].l-1;w++){
				int ind=(sd[xa].a)[w],sum=(sd[xa].t)[w]+xt;
				if(dijkstra[ind][i]>sum){
					cross[ind][i]=cross[i][ind]=xa;
				}
				dijkstra[ind][i]=(dijkstra[ind][i]>sum)?sum:dijkstra[ind][i];
		
	
				dijkstra[i][ind]=dijkstra[ind][i];
				bee[i][ind]=true;
				bee[ind][i]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijk(i);
	}
	for(int i=0;i<q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=2305842009213693592;
		for(int w=0;w<sd[x].l;w++){
			for(int b=0;b<sd[y].l;b++){
				ll xx=(sd[x].a)[w],yy=(sd[y].a)[b];
				if(xx>yy)swap(xx,yy);
//				cout<<"xx:"<<xx<<" yy:"<<yy<<" (sd[x].t)[w]:"<<(sd[x].t)[w]<<" (sd[y].t)[b]"<<(sd[y].t)[b]<<endl;
				ll ans2=dijkstra[xx][yy]+(sd[x].t)[w]+(sd[y].t)[b];
//				cout<<"ans2:"<<ans2<<" cro yy xx:"<<cross[yy][xx]<<" cro xx yy:"<<cross[xx][yy]<<endl;
				if(xx!=yy){
					if(cross[yy][xx]==x)ans2-=(sd[x].t)[w];
					if(cross[xx][yy]==y)ans2-=(sd[y].t)[b];
				}
				ans=(ans<ans2)?ans:ans2;
			}
		}
//		cout<<"ans:"<<ans<<endl;
		cout<<ans+tsub[x]+tsub[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/

