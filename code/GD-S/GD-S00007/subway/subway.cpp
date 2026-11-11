#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[500005];
int k[500005];
long long a,t;
int tim=0;
vector<pair<long long,long long>> v[500505];
int use[500505];
long long bfs(long long s,long long e){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
	q.push({0,s});
	while(!q.empty()){
		auto x=q.top();
		q.pop();
//		cout << x.second << ' ';
		if(x.second==e){
			return x.first;
		}
		for(auto i : v[x.second]){
//			cout << i.first << ' ';
			if(use[i.first]>i.second+x.first){
				use[i.first]=i.second+x.first;
				q.push({i.second+x.first,i.first});
			}
		}
//		cout << endl;
	}
	return 0x3f;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i <= m;i++){
		cin >> w[i];
	}
	for(int i=1;i <= n;i++){
		cin >> k[i];
		for(int j=1;j <= k[i];j++){
			cin >> a >> t;
			v[a].push_back({500000+i,t});
			v[500000+i].push_back({a,t});
		}
	}
	long long s,e;
	for(int i=1;i <= q;i++){
		cin >> s >> e;
		for(int j=1;j <=500500;j++){
			use[j]=0x3f3f;
		}
		cout << bfs(s,e)+w[s]+w[e] << endl;
//		cout << endl;
	}
//	cout << 0x3f;
	return 0;
} 
