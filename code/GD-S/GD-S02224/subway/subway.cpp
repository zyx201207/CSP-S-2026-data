#include<bits/stdc++.h>
using namespace std;

//struct lu{
//	long long zh=0;
//	long long xl=0;
//};

long long c=0, n=0, m=0, d=0, q=0, w[500005]={0}, k[505]={0}, t[500005]={0};
vector<long long> a[500005], b[505];
map<pair<long long, long long>, long long> mp;
queue<long long> p;
bool jg[500005]={0};

int bfs(int qd, int zd){
	while(!p.empty()){
		p.pop();
	}
	memset(t, 0, sizeof t);
	memset(jg, 0, sizeof jg);
	p.push(qd);
	t[qd]=0;
	jg[qd]=1;
//	cout<<'a';
	while(!p.empty()){
//		cout<<'a';
		long long tp=p.front();
		cout<<tp<<' '<<t[tp]<<endl;
		if(tp==zd){
			return t[tp];
		}
		for(int i=0; i<a[tp].size(); i++){
//			cout<<'a'<<' '<<a[tp][i];
			for(int j=0; j<b[a[tp][i]].size(); j++){
//				cout<<'a';
				if(!jg[b[a[tp][i]][j]]){
					p.push(b[a[tp][i]][j]);
					jg[b[a[tp][i]][j]]=1;
					pair<long long, long long> pp, ppp;
					pp.first=a[tp][i];
					pp.second=tp;
					ppp.first=a[tp][i];
					ppp.second=b[a[tp][i]][j];
					if(t[b[a[tp][i]][j]]==0){
						t[b[a[tp][i]][j]]=t[tp]+mp[pp]+mp[ppp];
					}
					else{
						t[b[a[tp][i]][j]]=min(t[tp]+mp[pp]+mp[ppp], t[b[a[tp][i]][j]]);
					}
				}
			}
		}
//		cout<<'a';
		p.pop();
	}
	return t[zd];
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		scanf("%lld", &w[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%lld", &k[i]);
		for(int j=1; j<=k[i]; j++){
			long long aa=0, cc=0;
			scanf("%lld%lld", &aa, &cc);
			a[aa].push_back(i);
			b[i].push_back(aa);
			pair<long long, long long> u;
			u.first=i;
			u.second=aa;
			mp[u]=cc;
		}
	}
	for(int i=1; i<=q; i++){
		long long x=0, y=0;
		scanf("%lld%lld", &x, &y);
		long long ans=0;
		ans=bfs(x, y)+w[x]+w[y];
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
