#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=3e5+5;
int n,m;
int num[N],nt[N],pre[M],ans[M];
int dp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>num[i];
	for (int i=n;i>=1;i--){
		int c=num[i];
		if (!pre[c]) pre[c]=i;
		else{
			nt[i]=pre[c];
			pre[c]=i;
		}
	}
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++) dp[i]=0;
		for (int i=n;i>=1;i--){
			int c=num[i],k=i+1;
			if (nt[i]) k=nt[i];
			if (c==j) dp[i]=1;
			dp[i]=max(dp[i],dp[k]);
			ans[j]+=dp[i];
		}
	}
	
	for (int j=1;j<=m;j++) cout<<ans[j]<<" ";
	return 0;
}
