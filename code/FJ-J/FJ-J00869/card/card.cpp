#include <cstdio>
#include <stack>
#define N 500005
#define M 300005
using namespace std;

int n, m, a[N], ans[M], cnt[M];
stack<int> stk; 

void clear(int x) {
	if(x != 0){
		while(!stk.empty()){
			int tmp=stk.top();
			if(tmp == x) break;
			stk.pop();
			cnt[tmp]--;
		}
		return ;
	}
	while(!stk.empty()){
		stk.pop();
	}
	for(int i=1;i<=m;i++){
		cnt[i]=0;
	}
	return ;
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	for(int i=1;i<=n;i++){
		clear(0);
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			stk.push(a[j]);
			if(cnt[a[j]] > 1){
				stk.pop();
				clear(a[j]);
				cnt[a[j]]--;
			}
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]) ans[j]++; 
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
