#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a[500005],t[500005],x[500005],y;
long long di[500005];
//vector<vector<long long>>di(500005,vector<long long>(500005,1e16));
//unordered_map<long long,unordered_map<long long,long long>>di;
struct lll{
	int u;
	long long w;
};
vector<lll>pl[500005];
long long dj(int st,int ed){
	for(int i=0;i<=m+1;i++)di[i]=1e16;
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>qu;
	qu.push({st,0});
	di[st]=0;
//	di[st][st]=0;
	while(!qu.empty()){
//		long long v=qu.top().second;
		int to=qu.top().first;
		qu.pop();
		for(auto i:pl[to]){
			if(di[i.u]>di[to]+i.w){
				di[i.u]=di[to]+i.w;
				qu.push({i.u,di[i.u]});
			}
		}
//		if(di[st][to]>di[st][st]+v){
//			di[st][to]=di[st][st]+v;
//			qu.push({to,di[st][to]});
//		}
	}
	return di[ed];
}
long long sol(int x2,int y2,int ch){
	long long ans=0;
	ans+=w[x2]+w[y2];
	if(ch==x2&&ch!=0)ans+=di[y2];
	else ans+=dj(x2,y2);
	
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int j2=j+1;j2<=k;j2++){
				if(j==j2)continue;
				pl[a[j]].push_back({a[j2],t[j]+t[j2]});
				pl[a[j2]].push_back({a[j],t[j]+t[j2]});
			}
		}
	}
	int ii=1;
	while(q--){
		cin>>x[ii]>>y;
		cout<<sol(x[ii],y,x[ii-1])<<'\n';
		ii++;
	}
	return 0;
}
