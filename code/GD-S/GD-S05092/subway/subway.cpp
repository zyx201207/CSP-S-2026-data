#include<bits/stdc++.h>
using namespace std; 
const int N = 505;
const int M = 1005;
int c, n, m, d, p, x, y, ans;
int w[M], k, a[N][M], t[N][M], num[N];
vector<int> line[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &p);
    for(int i=1; i<=m; i++){
    	scanf("%d", &w[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &k);
		for(int j=1; j<=k; j++){
			scanf("%d", &a[i][j]);
			scanf("%d", &t[i][a[i][j]]);
			line[a[i][j]].push_back(i);
			num[a[i][j]]++;
		}
	}
	while(p--){
		ans = 0;
		scanf("%d%d", &x, &y);
		ans += (w[x]+w[y]);
		bool flag = 0;
		int inin;
		for(int i=0; i<num[x]; i++){
			for(int j=0;  j<num[y]; j++){
				if(line[x][i] == line[y][j]){
					inin = line[x][i];
					flag = 1;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(flag){
			ans+=(t[inin][x]+t[inin][y]);
			printf("%d\n", ans);
		}else{
			int n1, n2, sum;
			bool flag1 = 0;
			bool flag2 = 0;
			for(int i=1; i<=n; i++){
				n1 = 0;
				n2 = 0;
				flag1 = 0;
				flag2 = 0;
				for(int j=0; j<num[x]; j++){
					for(int k=0;  k<num[i]; k++){
						if(line[x][j] == line[i][k]){
							n1 = line[x][j];
							flag1 = 1;
							break;
						}
					}
					if(flag1){
						break;
					}
				}
				for(int j=0; j<num[y]; j++){
					for(int k=0;  k<num[i]; k++){
						if(line[y][j] == line[i][k]){
							n2 = line[y][j];
							flag2 = 1;
							break;
						}
					}
					if(flag2){
						break;
					}
				}
				if(flag1 && flag2){
					sum = i;
					break;
				}
			}
			ans+=(t[n1][x]+t[n1][sum]+t[n2][sum]+t[n2][y]);
			printf("%d", ans); 
		}
	}
	return 0;
}

