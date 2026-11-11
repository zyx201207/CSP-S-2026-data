#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long c,n,m,d,q,a[maxn],k[maxn],x,y,vis[maxn]; 
struct pri{
	long long dest,need;
};
vector <pri>sub[maxn];
vector <long long>pr[maxn];
vector<pri> point[maxn];
void search(long long now){
	long long re;
	for(pri qu:point[now]){
		for(pri p:sub[qu.dest]){
			if(vis[p.dest]<=p.need+vis[now]+qu.need){
				if(p.dest==y)break;
				continue;
			}
			if(p.dest==y){
				vis[p.dest]=vis[now]+qu.need+p.need;
				break;
			}
			vis[p.dest]=vis[now]+qu.need+p.need;
			search(p.dest);
		}
	}
}
int main(){   
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		long long lst;
		for(int j=1;j<=k[i];j++){
			long long p,ne;cin>>p>>ne;
			if(j==1)lst=p;
			else {
				sub[lst].push_back({p,ne});
				sub[p].push_back({lst,ne});
			}
			point[p].push_back({i,ne});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		memset(vis,0x3f3f3f3f,sizeof(vis));
		vis[x]=0;search(x);
		cout<<vis[y]+a[x]+a[y]<<'\n';
	}
	return 0;
}
