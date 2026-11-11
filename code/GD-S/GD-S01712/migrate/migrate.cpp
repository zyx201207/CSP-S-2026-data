#include<bits/stdc++.h>
using namespace std;
bool flag1 = true,flag2 = false;
long long c,t,n,d,ans,minr,res,x[2000005];
void solve1(){
	long long b = x[2] - x[1];
	long long e = d / b;
	if(n % 2 == 1 && (n - 1) / 2 <= e){
		cout<<0<<'\n';
		return;
	}
	for(int i = 1;i < d;i++){
		long long tmp = e + i;
		ans += (n - tmp);
	}
	cout<<ans<<'\n';
	return;
}
bool bfs(int u,int ed){
	queue<pair<int,int>> q;
	q.push({u,0});
	while(!q.empty()){
		auto tmp = q.front();q.pop();
		if(tmp.second == ed){
			if(!minr){
				minr = tmp.second;
				res++;
			}else{
				if(tmp.second == minr)
					res++;
			}
			if(res > 2) return false; 
		}else{
			if(tmp.second >= minr) continue;
			for(int i = tmp.first + 1;i <= ed && x[i] - x[tmp.first] <= d;i++)
				q.push({i,tmp.second + 1});
		}
	}
	return res == 2;
}
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		flag1 = true,flag2 = false;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			if((x[i] - x[i - 1] != x[i - 1] - x[i - 2]) && (i >= 3)) flag1 = false;
		}
		for(int i = 1;i <= n;i++){
			if(x[i] - x[1] <= d && x[n] - x[i] <= d){
				flag2 = true;
				break;
			}
		}
		if(flag1){solve1();
		}else if(flag2){cout<<0<<'\n';
		}else{
			for(int i = 1;i <= n;i++){
				for(int j = i + 1;j <= n;j++){
					res = 0,minr = 5005;
					if(bfs(i,j)) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	} 
	return 0;
} 
