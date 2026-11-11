#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(int seat,int now,long long sum){
	long long manb=sum&a[seat];
	if(manb<=ans)return;
	if(now==0){
		ans=max(ans,manb);
		return;
	}
	for(int i=seat+1;i<=n-now+1;i++){
		dfs(i,now-1,manb);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout << a[1];
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)dfs(i,m-1,a[i]);
	cout << ans;
	return 0;
}
