#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
int c,n,m,d,q,w[500005],k,l,r,s,dis[500005],vis[500005],ta[500005],at[500005],di;
vector<pair<int,int> >v[500005];
struct qwe{
	int a,b;
	friend bool operator<(qwe a,qwe b){
		return a.a>b.a;
	}
};
priority_queue<qwe>pq;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ta[j]>>at[j];
		}
		for(int j=1;j<=k;j++){
			for(int kk=j+1;kk<=k;kk++){
				v[ta[j]].pb({ta[kk],at[j]+at[kk]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		for(int i=1;i<=m;i++){
			dis[i]=0x3f3f3f3f3f3f3f3f;
			vis[i]=0;
		}
		while(pq.size())pq.pop();
		dis[l]=0;
		pq.push({0,l});
		while(pq.size()){
			int a1=pq.top().a,a2=pq.top().b;
			pq.pop();
			if(a1>dis[a2])continue;
			dis[a2]=a1;
			if(vis[a2])continue;
			vis[a2]=1;
			if(a2==r){
				cout<<a1+w[l]+w[r]<<endl;
				break;
			}
			for(int i=0;i<v[a2].size();i++){
				if(!vis[v[a2][i].fi]&&dis[v[a2][i].fi]>dis[a2]+v[a2][i].se){
					pq.push({dis[a2]+v[a2][i].se,v[a2][i].fi});
				}
			}
		}
	}
	return 0;
}
