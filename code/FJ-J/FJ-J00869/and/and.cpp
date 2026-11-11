#include <cstdio>
#include <algorithm>
#define N 200005
using namespace std;

int n, m;
long long a[N], ans=-1, tmp;
bool mark[N]; 

void dfs(int id, long long v){
	if(id >= m){
		ans=max(ans, v);
		return ;
	}
	
	for(int i=1;i<=n;i++){
		if(mark[i]) continue;
		mark[i]=true;
		dfs(id+1, v&a[i]);
		mark[i]=false;
	}
	
	return ;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	if(m == n-1){
		for(int i=1;i<=n;i++){
			tmp=2147483647;
			for(int j=1;j<=n;j++) {
				if(j == i) continue;
				tmp&=a[j];
			}
			ans=max(ans, tmp);
		} 
		printf("%lld", ans);
		return 0;
	}
	if(m == 2){
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++){
				tmp=a[i];
				tmp&=a[j];
				ans=max(ans, tmp);
			}
		}
		printf("%lld", ans);
		return 0;
	}
	if(m == 1){
		for(int i=1;i<=n;i++){
			ans=max(ans, a[i]);
		}
		printf("%lld", ans);
		return 0;
	}
	if(n <= 20){
		dfs(0, 2147483647);
		printf("%lld", ans);
		return 0;
	}
	return 0;
}
