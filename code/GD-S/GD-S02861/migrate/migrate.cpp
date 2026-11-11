#include <bits/stdc++.h>
using namespace std;

long long c,t,ans,l,w;
long long n,d;
long long pq;
vector<long long> s;
vector<int> q;

void dfs(long long location,long long w,long long t){
	if(location == w){
		pq++;
		return;
	}
	if(t <= 0){
		return;
	}
	for(long long i = location + 1;i <= w;i++){
		if(s[w] - s[i] <= d){
			dfs(i,w,t - 1);
		}
	}
}

long long f(long long v,long long w){
	long long len = (s[n] - s[1]) / d;
	if((s[n] - s[1]) % d != 0){
		len++;
	}
	return len;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t){
		ans = 0;
		s = {};
		cin >> n >> d;
		s.push_back(0x3f3f3f);
		for(long long i = 1,o;i <= n;i++){
			cin >> o;
			s.push_back(o);
		}
		for(long long i = 0;i <= n;i++){
			q.push_back(1);
		}
		for(long long j = 2;j <= n;j++){
			pq = 0;
			l = f(1,j);
			dfs(1,j,l);
			if(pq == 2){
				cout << 1 << " "<< j << "\n";
				ans++;
			}
		}
//		cout << "len " << l << "\n";
		cout << ans << "\n";
		t--;
	}
}
