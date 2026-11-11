#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long m;
int long a[500010];
int long d[500010];
int long dp[500010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		d[i]=a[i-1]-a[i];
	}
	for(int i=1;i<=n;i++){
		int bas=1,j=1;
		d[i]=0;
		while(m>=0){
			if(i+j>n) break;
			if(m-d[i]-d[i+j]<0) break;
			dp[i+j]=dp[i+j-1]+d[i+j];
			dp[i+j-1]=0;
			bas++;
			d[i]+=dp[i+j];
			j++;
		}
		if(bas>cnt) cnt=bas;
		dp[i+j-1]=0;
		dp[i+j]=0;
	}
	cout<<cnt;
	return 0;
}