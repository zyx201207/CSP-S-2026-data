#include<bits/stdc++.h>
using namespace std;

int flag[200005];
int a[200005];
int n,m;
int ans = 0;
void dfs1(int x,int num){
	if (x == m){
		int cnt = -1;
		for (int i = 1;i <= n;i++){
			if (flag[i]){
				if (cnt == -1) cnt = a[i];
				else cnt = cnt & a[i];
			}
		}
		ans = max(ans,cnt);
		return;
	}
	for (int i = 1;i <= n;i++){
		if (!flag[i]){
			flag[i] = 1;
			dfs1(x+1,i);
			flag[i] = 0;
		}
	}
	return;
}
void dfs2(int x,int num){
	if (x == m){
		int cnt = -1;
		for (int i = 1;i <= n;i++){
			if (flag[i]){
				if (cnt == -1) cnt = a[i];
				else cnt = cnt & a[i];
			}
		}
		ans = max(ans,cnt);
		return;
	}
	for (int i = 1;i <= n;i++){
		if (flag[i]){
			flag[i] = 0;
			dfs2(x+1,i);
			flag[i] = 1;
		}
	}
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	if (m == 1) printf("0");
	else{
		if (m < n / 2){
			for (int i = 1;i <= n-m+1;i++){
				flag[i] = 1;
				dfs1(1,i);
				flag[i] = 0;
			}
		}
		else{
			m = n - m;
			for (int i = 1;i <= n;i++) flag[i] = 1;
			for (int i = 1;i <= n-m+1;i++){
				flag[i] = 0;
				dfs2(1,i);
				flag[i] = 1;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
