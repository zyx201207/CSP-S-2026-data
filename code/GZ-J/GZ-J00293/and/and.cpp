//GZ-J00293 »Æçûä¿ 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans = -1;
void dfs(long long i,long long num,long long cnt){
	if(cnt == m){
		ans = max(ans,num);
		return;	
	}
	if(i == n)return;
	dfs(i+1,num & a[i],cnt+1);
	dfs(i+1,num,cnt);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	dfs(1,((2ll << 30) - 1ll),0);
	cout << ans;
	return 0;
}
