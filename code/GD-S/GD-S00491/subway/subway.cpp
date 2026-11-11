#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,qq;
vector<pair<long long,long long> > v[5000000+10];
long long w[5000000+10];
long long ans[5000000+10];
long long a[510][510],t[510][510];
struct Po{
	long long id;
	long long s;
	Po(long long id_=0,long long s_=0){
		id=id_;
		s=s_;
	}
	bool operator<(const Po& b)const{
		return s>b.s;
	}
	bool operator>(const Po& b)const{
		return !((*this)<b);
	}
};
priority_queue<Po> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qq;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
			if(j!=1){
				v[a[i][j-1]*m+i].push_back({a[i][j]*m+i,0});
				v[a[i][j]*m+i].push_back({a[i][j-1]*m+i,0});
			}
			v[a[i][j]].push_back({a[i][j]*m+i,t[i][j]});
			v[a[i][j]*m+i].push_back({a[i][j],t[i][j]});
		}
//		for(int j=1;j<=k;j++){
//			cin >> t[i][j];
//			v[a[i][j]].push_back({a[i][j]*m+i,t[i][j]});
//			v[a[i][j]*m+i].push_back({a[i][j],t[i][j]});
//		}
	}
//	for(int i=1;i<=500000+10;i++){
//		if(v[i].size()!=0)t=i;
//	}
	while(qq--){
		long long x,y;
		cin >> x >> y;
		memset(ans,0x3f,sizeof(ans));
		ans[x]=0;
		q.push({x,0});
		while(!q.empty()){
			Po y=q.top();
			q.pop();
			if(ans[y.id]!=y.s)continue;
			for(auto i:v[y.id]){
				if(i.second+y.s<ans[i.first]){
					ans[i.first]=i.second+y.s;
					q.push({i.first,ans[i.first]});
				}
			}
		}
		cout << ans[y]+w[x]+w[y] << '\n';
	}
	return 0;
}
