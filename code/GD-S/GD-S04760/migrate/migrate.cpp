#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2000010;
LL n, d;
LL x[N];
PII num[N];
queue<PII> q;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while(T--){
		scanf("%lld%lld", &n, &d);
		int res = 0;
		for(int i = 1;i <= n;i++){
			scanf("%lld", &x[i]);
		}
		for(int i = 1;i < n;i++){
			for(int j = i;j <= n;j++) num[j] = {0, 0};
			while(!q.empty()) q.pop();
			q.push({i, 0});
			while(!q.empty()){
				PII last = q.front();
				q.pop();
				for(int j = last.x + 1;x[j] - x[last.x] <= d && j <= n;j++){
					q.push({j, last.y + 1});
					if(!num[j].x) num[j] = {1, last.y + 1};
					else{
						if(num[j].y == last.y + 1){
							if(num[j].x == 1){
								num[j].x++;
								res++;
							}
							else if(num[j].x == 2){
								num[j].x = -1;
								res--;
							}
						}
					}
				}
			}
		}
		printf("%d\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
