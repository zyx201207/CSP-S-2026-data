#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 7;
ll x[N],mxd,n;
vector<int> to[N];
int d[N];ll cnt[N];

int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int _ = 1,testid;cin >> testid >> _;
	while(_--){
		cin >> n >> mxd;
		for(int i=1;i<=n;i++)cin >> x[i];
		for(int i=1;i<=n;i++)to[i].clear();
		
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(abs(x[i] - x[j]) <= mxd)
					to[i].push_back(j);
							
		ll ans = 0;
		for(int i=1;i<=n;i++){
			queue<int> Q;Q.push(i);
			for(int j=1;j<=n;j++)d[j] = -1;
			for(int j=1;j<=n;j++)cnt[j] = 0;
			d[i] = 0,cnt[i] = 1;
			
			while(!Q.empty()){
				int x = Q.front();Q.pop();
				for(int v:to[x]){
					if(d[v] == -1)d[v] = d[x] + 1,cnt[v] = cnt[x],Q.push(v);
					else if(d[v] == d[x] + 1)cnt[v] += cnt[x];
				}
			}
			//for(int i=1;i<=n;i++)cerr << cnt[i] << " ";
			for(int i=1;i<=n;i++)
				if(cnt[i] == 2) ans ++;	
			//cerr << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}


/*
Code by mid27_ (luogu),
use cq's 10 life to let this code get a lot of scores!
RP+++++++++++++++++++++++++++++++++++++++++++
*/ 
