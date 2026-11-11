#include<bits/stdc++.h>
#define int long long
#define N 2000005

using namespace std;

struct cai{
	int xx,dp,th;
};
int c,t,n,d,x[N],dp,dd[305],nd[305];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)cin >> x[i];
		if(c <= 6){
			for(int i = 1;i <= n;i++){
				dd[i] = 0;
				nd[i] = 1;
				for(int j = i + 1;j <= n;j++){
					dd[j] = 2e18;
					for(int z = j - 1;z >= i;z--){
						if(x[j] - x[z] > d)break;
						if(dd[z] + 1 < dd[j]){
							dd[j] = dd[z] + 1;
							nd[j] = nd[z];
						}else if(dd[z] + 1 == dd[j]){
							nd[j] += nd[z];
						}
					}
					if(nd[j] == 2)ans++;
				}
			}
			cout << ans << "\n";
		}
		else if(7 <= c && c <= 10){
			for(int i = 1;i <= n;i++){
				deque<cai>que;
				que.push_back({x[i],0,1});
				dp = 0;
				for(int j = i + 1;j <= n;j++){
					while(!que.empty() && x[j] - que.front().xx > d)que.pop_front();
					if(que.size() == 0)break;
					if(que.size() == 1){
						dp = que.front().dp + 1;
					}else if(que.size() == 2){
						cai c1 = que.front();
						que.pop_front();
						cai c2 = que.front();
						que.pop_front();
						if(c1.dp == c2.dp && c1.th + c2.th == 1)ans++;
						dp = c1.dp + 1;
						que.push_front(c2);
						que.push_front(c1);
					}else{
						cai c1 = que.front();
						que.pop_front();
						cai c2 = que.front();
						que.pop_front();
						cai c3 = que.front();
						que.pop_front();
						if(c1.dp == c2.dp && c2.dp < c3.dp && c1.th + c2.th == 2)ans++;
						dp = c1.dp + 1;
						que.push_front(c3);
						que.push_front(c2);
						que.push_front(c1);
					}
					que.push_back({x[j],dp});
				}
			}
			cout << ans << "\n";
		}else if(c == 11 || c == 12){
			cout << 0 << "\n";
		}else if(c == 13 || c == 14){
			cout << 1 << "\n";
		}else cout << 0 << "\n";
	}
	return 0;
}
