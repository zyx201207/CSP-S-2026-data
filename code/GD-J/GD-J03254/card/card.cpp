#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,u,v;
int a[N],last[N],ans[N],dp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];last[a[i]]=i;
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		dp[last[a[i]]+1]+=dp[i];
		ans[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
