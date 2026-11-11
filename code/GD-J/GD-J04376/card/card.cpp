#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
//int s[N],top;
//bool vis[N];
int last[N];
int ans[N];
void solve(int x){
	if(x==0) return;
	ans[a[x]]++;
	solve(last[a[x+1]]);
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
//		ans[a[i]]=i;
	}
//	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
//	printf("\n");
//	for(int i=n;i>=1;i--){
//		if(vis[a[i]]){
//			while(s[top]!=a[i]){
//				int x=s[top--];
//				vis[x]=false;
//				ans[x]--;
//			}
//		}else{
//			s[++top]=a[i];
//			vis[a[i]]=true;
//		}
//		for(int i=1;i<=top;i++) printf("%lld ",s[i]);
//		printf("\n");
//	}
//	for(int i=1;i<n;i++){
//		if(last[a[i]]!=i){
//			mp[last[a[i]]].push_back(i);
//		}else{
//			mp[i+1].push_back(i);
//		}
//	}
//	dfs(n,0);
	for(int i=n;i>=1;i--){
		solve(last[a[i]]);
	}
	for(int i=1;i<=m;i++){
		printf("%lld",ans[i]);
		if(i!=m) printf(" ");
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
