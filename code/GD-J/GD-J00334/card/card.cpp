#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,pid,a[500005],use[300005],now[500005],sum[300005];
bool pand;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i++){
		cnt = 0;
		memset(use,0,sizeof use);
		memset(now,0,sizeof now);
		for(int j = i;j <= n;j++){
			if(use[a[j]] == 0){
				now[++cnt] = a[j];
				use[a[j]] = 1;
			}
			else{
				pand = 0;
				for(int k = 1;k <= cnt;k++){
					if(now[k] == a[j]){
						pand = 1;
						pid = k;
						continue;
					}
					if(pand){
						use[now[k]] = 0;
						now[k] = 0;
					}
				}
				cnt = pid;
			}
		}
		for(int t = 1;t <= cnt;t++){
			sum[now[t]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",sum[i]);
	}
	return 0;
}
