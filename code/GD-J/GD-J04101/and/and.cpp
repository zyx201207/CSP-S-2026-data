#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long cnt=-1e9;
long long a[200005];
void dfs(int now,int num,long long sum){
	if(num==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=now+1;i<=n;i++){
		dfs(i,num+1,sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=0;
		dfs(i,1,a[i]);
		cnt=max(cnt,ans);
	}
	cout<<cnt;
	return 0;
}
