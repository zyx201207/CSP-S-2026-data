#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
int n,m,ans;
int a[MAXN+5];

void dfs(int i,int cnt,int sum){
	if(sum<=ans) return;
	if(cnt==m){
		ans=sum;
		return;
	}
	for(int j=i+1;j<=n;++j) dfs(j,cnt+1,sum&a[j]);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n<=20){
		dfs(0,0,2147483647);
	}else if(m==1){
		for(int i=1;i<=n;++i) ans=max(ans,a[i]);
	}else if(m==2){
		for(int i=1;i<=n;++i) for(int j=1;j<i;++j) ans=max(ans,a[i]&a[j]);
	}else if(m==n){
		ans=2147483647;
		for(int i=1;i<=n;++i) ans&=a[i];
	}
	cout<<ans;
	return 0;
}
