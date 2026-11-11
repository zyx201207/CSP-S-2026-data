#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0},dp[500005]={0};
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;//存疑 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int l;//不包含当前位所需维护位数 
	dp[1]=0;///一个不消耗次数 
	for(int i=2,j=1;i<=n;i++){
		l=i-j;
		dp[i]=dp[i-1]+l*(a[i]-a[i-1]);//上次所用次数+维护长度*单个增加所用次数
		while(dp[i]>m){//超了 
			dp[i]-=a[i]-a[j];
			j++;
		} 
		if(i-j+1>ans){
			ans=i-j+1;
		}
	}
	cout<<ans;
	return 0;
}
