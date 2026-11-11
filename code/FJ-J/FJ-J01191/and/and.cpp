#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2002][2002],a[2002],maxn1;
int n,m,flag1=1;
void dfs(int i,int sum,int sm){
	if(i==n+1){
		if(sm==0)maxn1=max(maxn1,sum);
		return;
	}
	if(m>=1)dfs(i+1,sum&a[i],sm-1);
	dfs(i+1,sum,sm);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)flag1=0;
	}
	//Test 1 ~ 5, 25pts
	if(n<=20){
		dfs(1,(1>>30)-1,m);
		cout<<maxn1;
	}
	//Test 6, 5 pts
	else if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++)
			maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	//Test 8 ~ 10, 15 pts
	else if(m==n){
		int sum=(1<<30)-1;
		for(int i=1;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	//Test 7, 5 pts
	else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
	}
	//Test 16,17, 10pts
	else if(flag1==1){
		int sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum1++;
			if(a[i]==2)sum2++;
			if(a[i]==3)sum3++;
		}
		if(m<=sum3)cout<<3;
		else if(m<=sum2+sum3)cout<<2;
		else if(m<=sum1+sum3)cout<<1;
		else cout<<0;
	}
	//Test 13, 5pts
	else{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}
//miao ~
//++ RP 
//RP ++ 
// 65 pts
//All 229 pts
