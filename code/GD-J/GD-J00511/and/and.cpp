#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;
ll ans=0;
int num[N],vis[N];
void dfs(int d,ll sum){
	if (d>m){
		ans=max(ans,sum);
		return;
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			vis[i]=1;
			dfs(d+1,sum&num[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>num[i];
	dfs(1,(1<<31)-1);
	cout<<ans;
	return 0;
}
