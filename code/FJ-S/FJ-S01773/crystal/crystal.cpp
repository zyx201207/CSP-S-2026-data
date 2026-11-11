#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
long long n,m;
long long a[N];
long long dp[N];//到以第n个水晶为结尾最多能用多少克水晶合成大水晶
long long s[N];//前缀和数组负责记录 
long long cz[N];
long long mx=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		cz[i]=i*a[i]-s[i];
	}
	dp[1]=0;//一个水晶无法合成 
	for(int i=2;i<=n;i++){
	if(m>=cz[i]){
		dp[i]=i;
	}
	else{
		for(int j=1;j<=i;j++){
			if(m>=cz[i]-cz[j]){
				dp[i]=(i-j);
			}
		}
	}
  }
  for(int i=1;i<=n;i++){
  	mx=max(mx,dp[i]);
  }
  cout<<mx;
	
	
	
	
	return 0;
}
