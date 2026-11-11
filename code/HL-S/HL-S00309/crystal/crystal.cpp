#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000],dp[1000000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]-i*(a[i]-a[i-1])-(a[i]-a[i-1]);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dp[i]==m){
			ans=i;
		}else if(dp[i]>m){
			ans=i-2;
		}
	}
	cout<<ans;
    return 0;
}

