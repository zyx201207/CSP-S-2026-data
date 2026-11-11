#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],p[35][200005],mx,f[200005],all,best;
long long sum;
bool flag;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		int num = a[i],cnt = 0;
		while(num){
			if(num % 2){
				p[cnt][i] = 1;
				if(cnt > mx){
					mx = cnt;
				}
			}
			num /= 2;
			cnt++;
		}
	}
	for(int i = mx;i >= 0;i--){
		if(!flag){
			int num = 0;
			for(int j = 1;j <= n;j++){
				if(p[i][j] == 1){
					f[++num] = j;
				}
			}
			if(num < m){
				memset(f,0,sizeof(f));
			}
			else{
				all = num;
				best = num;
				flag = 1;
			}
		}
		else if(best > m){
			for(int j = 1;j <= all;j++){
				if(f[j] == 0) continue;
				if(p[i][f[j]] == 0){
					f[j] = 0;
					best--;
					if(best == m) break;
				}
			}
		}
		else{
			break;
		}
	}
	flag = 0;
	for(int i = 1;i <= all;i++){
		if(f[i] != 0 && !flag){
			sum = a[f[i]];
			flag = 1;
		}
		else if(f[i] != 0){
			sum = sum & a[f[i]];
		}
	}
	printf("%lld",sum);
	return 0;
}

