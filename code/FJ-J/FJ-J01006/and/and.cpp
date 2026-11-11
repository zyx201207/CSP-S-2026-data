#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int a[200010];
bool dat[200010][35];//第i个数&1<<j位的结果 
int n,m;
int ans;
void dfs(int pos,int s,int sum){
	if(pos==n+1){
		if(s==m){
			ans=max(ans,sum);
		}
		return;
	}
	dfs(pos+1,s+1,sum&a[pos]);
	dfs(pos+1,s,sum);
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int mmx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmx=max(mmx,a[i]);
	}
	if(m==n){
		int ss=LLONG_MAX;
		for(int i=1;i<=n;i++){
			ss=(ss&a[i]);
		}
		cout<<ss<<endl;
		return 0;
	}
	if(n<=20){
		dfs(1,0,LLONG_MAX);
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx<<endl;
		return 0;
	}
	if(m==2){
		int mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx<<endl;
		return 0;
	}//暴力部分50pts
	if(mmx<=4){
		sort(a+1,a+n+1,cmp);
		int sum=LLONG_MAX;
		for(int i=1;i<=m;i++){
			sum=(sum&a[i]);
		}
		return 0;
	}
	for(int i=0;i<=30;i++){
		for(int j=1;j<=n;j++){
			dat[j][i]=a[j]&(1<<i);
		}
	}
	int mn=LLONG_MAX;
	for(int i=1;i<=n;i++){
		mn=min(mn,a[i]);
	} 
	return 0;
}
//nlogn or n 
/*
4 2 
0011 1111 1100 1100 
*/
//n个数 选择m个 
//与的数值最大
//与：下去了就上不来
//dp:dp[i][j]表示前i个数字选择j个数字与的最大值 
//dp[i][j]=dp[i-1][] 
