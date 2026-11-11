#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
int c, t, n, d, x[N], tt[N], ss[N], cnt[5000][5000], ans;
//tt[i]，以i为终点路径唯一的数量
//ss[i], 以i为起点路径唯一的数量 
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--){
		scanf("%lld%lld", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
			ss[i] = tt[i] = 1;
		}
		if(n <= 5000){
			ans = 0;
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++) cnt[i][j] = 0;
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++) 
					if(x[j] - x[i] <= d) cnt[i][j]++, cnt[j][i]++;
			}
			for(int k = 1; k <= n; k++)
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= n; j++)
						cnt[i][j] += cnt[i][k] * cnt[k][j];
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++) 
					if(cnt[i][j] == 2) ans++;
			printf("%d\n", ans);
			continue;
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			int j = (x[i] + d >= x[n] ? n : upper_bound(x + i, x + n + 1, x[i] + d) - x - 1); 
			ss[i] += j - i;
			while(j < n){
				int nxt = (x[j] + d >= x[n] ? n : upper_bound(x + j, x + n + 1, x[j] + d) - x - 1); 
				int nnxt = (x[j - 1] + d >= x[n] ? n : upper_bound(x + j - 1, x + n + 1, x[j - 1] + d) - x - 1); 
				ss[i] += nxt - nnxt;
				j = nxt;
			}
		}
		for(int i = 1; i <= n; i++){
			int j = (x[i] - d <= x[1] ? 1 : upper_bound(x + 1, x + i + 1, x[i] - d) - x);
			while(j > 1){
				int nxt = (x[j] - d <= x[1] ? 1 : upper_bound(x + 1, x + j + 1, x[j] - d) - x); 
				int nnxt = (x[j + 1] - d <= x[1] ? 1 : upper_bound(x + 1, x + j + 2, x[j + 1] - d) - x); 
				tt[i] += nnxt - nxt;
				j = nxt;
			}
		}
		for(int i = 1; i <= n - 1; i++){ //跳跃的起点 
			int nxt = (x[i] + d >= x[n] ? n : upper_bound(x + i, x + n + 1, x[i] + d) - x - 1); 
			//跳一步的最高点
			if(nxt == i + 1) continue; 
			int tmp2 = (x[nxt - 1] + d >= x[n] ? n : upper_bound(x + i, x + n + 1, x[nxt - 1] + d) - x - 1);
			//跳一步的次高点再跳一步能到达的最高点 
			if(nxt == i + 2){
				ans += tt[i] * (tmp2 - nxt) * ss[tmp2];
				//从i出发的元组终点为nxt+1~tmp2
				//往前，什么点跳到这个元组路径唯一？答：刚好跳1步，2步，3步...且必须再跳一步跳到nxt的点  
				continue;
			}
			int tmp3 = (x[nxt - 2] + d >= x[n] ? n : upper_bound(x + i, x + n + 1, x[nxt - 2] + d) - x - 1);
			//跳一步能到达的次次高点跳一步能到达的最高点
			ans += tt[i] * (tmp2 - tmp3) * ss[tmp2];
		} 
		printf("%lld\n", ans);
		//我们可以推测，双径岛屿对一定最短距离为2
		//不对哦，只是每个小的元组长度都为2，但还要算上前面的和后面的数值！
		//如果距离小于2，一步可达，不存在多种
		//如果距离大于2，一定会有第三种路径
		//由此可以推知，我们每次只需要考虑跳两步跳到的点
		//这些点在哪里呢？
		//一定是起点跳到可达的最高点(nxt)之后再跳一步（高度不限）达到的点
		//nxt到新的点一步，且nxt-1到新的点也是一步，再之前的点不可到达 
	}
	return 0;
}
