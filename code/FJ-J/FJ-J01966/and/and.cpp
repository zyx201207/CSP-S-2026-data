#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010];
int ans;
int dp(int d,int res,int x){
	if(d>n)return -1;
	if(x==m){ 
		return res;
	}
	return max(dp(d+1,res&a[d+1],x+1),dp(d+1,res,x));
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(dp(i,a[i],1),ans);	
	}
	cout<<ans;
	return 0;
}

