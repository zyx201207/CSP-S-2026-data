#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],b,e;
pair<long long,long long> dfs(long long u,long long v,long long a){
	long long minn = 2147483647,sum = 1;
	if(u == v) return make_pair(a,1);
	for(long long i = u + 1 ; i <= v ; i++){
		if(x[i] - x[u] > d) return make_pair(-1,sum);
		if(minn == dfs(i,v,a+1).first && minn != -1) sum++;
		else if(minn > dfs(i,v,a+1).first && minn != -1) sum = 1,minn = dfs(i,v,a+1).first;
	}
	return make_pair(minn,sum);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		long long sum = 0;
		for(long long i = 1 ; i <= n ;i++) cin >> x[i];
		for(long long i = 1 ; i <= n ; i++){
			for(long long j = i + 3 ; j <= n ; j++){
				b = i,e = j;
				pair<long long,long long> a = dfs(i,j,0);
				if(a.second == 2){
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
