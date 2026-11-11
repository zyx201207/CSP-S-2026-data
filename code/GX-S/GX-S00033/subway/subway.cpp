#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int as;
long long d;
long long a[2000010];
int dis[5010][5010];
int ct[5010][5010];
int Begin[5010], To[25000010], Next[25000010], etot;
void add(int x, int y){
    To[++etot] = y;
    Begin[x] = etot;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d", &T);
	scanf("%d", &T);

	while(T--){
		memset(dis, 0x3f, sizeof(dis));
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
		}
		for(int i = 1; i <= n; i++){
		    dis[i][i] = 0;
            for(int j = 1; j <= n; j++){
                if(a[j] + a[i] <= d) dis[i][j] = 1;
            }
		}
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                        ct[i][j] = 1;
					}
					else if(dis[i][j] == dis[i][k] + dis[k][j]){
                            ct[i][j]++;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
				    if(ct[i][j] == 2 && dis[i][j] == 1061109567) as++;
				}
        }
	}
    printf("%d", as);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

