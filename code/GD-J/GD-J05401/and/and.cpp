#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n,m,a[N],dp[N],maxn,mpos;
int ans[N],maxn2,vis[N],pre[N],lst[N];
void dfs(int k){
	if(k==m+1){
		int sum=ans[1];
		for(int i=2;i<=m;i++){
			sum&=ans[i];
		}maxn2=max(maxn2,sum);
		return ;
	}for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[k]=a[i];
			dfs(k+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int k=1;
	for(int i=1;i<=32;i++){
		k<<=1;
	}k-=1;
	dp[0]=k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxn){
			maxn=a[i];
			mpos=i;
		}
	}pre[1]=a[1],lst[n]=a[n],pre[0]=k,lst[n+1]=k;
	for(int i=2;i<=n-1;i++){
		pre[i]=(pre[i-1]&a[i]);
		lst[n-i+1]=(lst[n-i+2]&a[n-i+1]);
	}
	if(n<=20){//1~5 25pts
		dfs(1);	
		cout<<maxn2<<" ";
		return 0;
	}
	if(n<=2005){
		if(m==1){//#6 5pts
			cout<<maxn;
			return 0;
		}if(m==2){//8~10 15pts
			int maxn3=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					maxn3=max(maxn3,(a[i]&a[j]));
				}
			}cout<<maxn3;
			return 0;
		}
	}
	if(m==n-1){//11~12 10pts
		int maxn4=0;
		for(int i=1;i<=n;i++){
			maxn4=max(maxn4,pre[i-1]&lst[i+1]);
		}cout<<maxn4;
		return 0;
	}
	for(int i=1;i<=n;i++){//乱打的dp不知能骗多少分 
//		if(i==mpos) continue;
		for(int j=m;j>=1;j--){
//			cout<<(dp[j-1]&a[i])<<endl;
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
	}
//	for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
	cout<<dp[m];
    return 0;
}
//10：09 共25+5+15+10+x 理想一共55+pts 
//到T3为止一共255 
