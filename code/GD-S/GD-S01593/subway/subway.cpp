#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500007;
const int M=507;
const ll inf=2e18;
int m,n,k,u,q,x,y,z,f[M];
ll d[M][M],db[N],ans;
vector<int>a[M];
vector<int>b[N];
vector<ll>c[N];
vector<int>v[M];
vector<int>w[M];
priority_queue< pair<ll,int> >pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&u,&m,&n,&k,&q);
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) if(i!=j) d[i][j]=inf;
	for(int i=1;i<=n;i++) scanf("%lld",&db[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			scanf("%d%d",&y,&z);
			a[i].push_back(y);
			b[y].push_back(i);
			c[y].push_back(z);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=0;k<b[i].size();k++){
				x=b[i][j];
				y=b[i][k];
				d[x][y]=min(d[x][y],c[i][j]+c[i][k]);
			}
		}
	}
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cerr<<d[i][j]<<' ';
		}
		cerr<<endl;
	}
	*/
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			pq.push(make_pair(-d[i][j],j));
			f[j]=1;
		}
		while(!pq.empty()){
			x=(pq.top()).second;
			pq.pop();
			f[x]=0;
			for(int j=1;j<=m;j++){
				//cerr<<i<<' '<<x<<' '<<j<<endl;
				if(d[i][j]>d[i][x]+d[x][j]){
					d[i][j]=d[i][x]+d[x][j];
					if(!f[j]){
						pq.push(make_pair(-d[i][j],j));
						f[j]=1;
					}
				}
			}
		}
	}
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cerr<<d[i][j]<<' ';
		}
		cerr<<endl;
	}
	*/
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ans=inf;
		for(int j=0;j<b[x].size();j++){
			for(int k=0;k<b[y].size();k++){
				ans=min(ans,c[x][j]+c[y][k]+d[b[x][j]][b[y][k]]);
			}
		}
		ans+=db[x]+db[y];
		cout<<ans<<endl;
	}
	return 0;
}
