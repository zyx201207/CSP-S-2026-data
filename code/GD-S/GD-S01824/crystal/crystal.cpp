#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100005],m;
long long dp[10005][10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	bool f=true;
	long long k=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=k){
			f=false;
			break;
		}
	}
	if(f){
//		cout<<"aef"<<endl;
		long long res=0;
		for(int i=n;i>=1;i--){
			res+=abs(a[n]-a[i]);
			if(res>m){
				printf("%d",n-i); 	
				return 0;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		dp[i][1]=0;
		for(int j=2;j<=i;j++){
			dp[i][j]=dp[i][j-1]+a[i]-a[i-j+1];
			if(dp[i][j]>m)break;
			ans=max(ans,j);
		}
	}
	printf("%d",ans);
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
