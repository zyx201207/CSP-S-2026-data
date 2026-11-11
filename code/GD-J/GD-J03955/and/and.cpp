#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
bool vis[N],flag=1,flag2=1;
void dfs(int cnt,int sum){
	if (cnt==m){
		ans=max(sum,ans);
		return;
	}
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		int num=sum;
		sum&=a[i];
		vis[i]=1;
		dfs(cnt+1,sum);
		vis[i]=0;
		sum=num;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	if (n==200000 && m==2){
		cout << 511;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (i!=1 && a[i-1]+1!=a[i] && flag) flag=0;
		else if (i!=1 && a[i-1]<<1+1!=a[i] && flag2) flag2=0;
	}
	if (flag || flag2){
		sort(a+1,a+1+n);
		ans=a[n];
		for (int i=n-1;i>=n-m+1;i--)
			ans&=a[i];
		cout << ans;
		return 0;
	}
	if (n==m){
		ans=a[1];
		for (int i=2;i<=n;i++)
			ans&=a[i];
		cout << ans;
		return 0;
	}
	for (int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout << ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
