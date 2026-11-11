#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m,a[N],ans,A = 1,B;

int check(int x){
	if (x == 1) return 1;
	int num = 1;
	for (int j = 1;j <= 20;j++){
		num <<= 1;
		if (num == x) return 1;
	}
	return 0;
}

void dfs(int idx,int num,int cnt){
	if (cnt == m){
		ans = max(ans,num);
		return;
	}
	if (idx > n || n-idx+1 < m-cnt) return;
	dfs(idx+1,num&a[idx],cnt+1);
	dfs(idx+1,num,cnt);
	return;
}

void solvea(){
	sort(a+1,a+1+n);
	ans = a[n+1-m];
	return;
}

void solveb(){
	sort(a+1,a+1+n);
	ans = INT_MAX;
	for (int i = 1;i <= m;i++) ans &= a[n+1-i];
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	B = check(n);
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		A &= check(a[i]+1);
		B &= (a[i] == i-1 ? 1 : 0);
	}
	if (A) solvea();
	else if (B) solveb();
	else dfs(1,INT_MAX,0);
	cout<<ans;
	return 0;
}
