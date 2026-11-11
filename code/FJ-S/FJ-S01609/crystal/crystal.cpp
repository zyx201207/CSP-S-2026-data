#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,c,ans=1;
long long m,s;
long long a[500005];
int dp[500005];
bool o,p;
void pian(int b){
	m-=c*b;
	if(m<0){
		ans=b;
		return;
	}
	pian(b+1);
}
void u(){
	for(int i=2;i<=n;i++){
		if(i==2) c=abs(a[i]-a[i-1]);
		if(i>2&&abs(a[i]-a[i-1])!=c) p=1;	
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) o=1;
		dp[i]=1;
	}
	sort(a+1,a+n+1);
	u();
	if(o==0||p==0){
		pian(1);
		cout<<ans;
		return 0; 
	}
	for(int i=2;i<=n;i++){
		s+=dp[i-1]*(a[i]-a[i-1]);
		if(s<=m){
			dp[i]=dp[i-1]+1;
		}else{
			dp[i]=dp[i-1]-((s-m-1)/(a[i]-a[i-1])+1);
			for(int j=1;j<=dp[i-1]-dp[i];j++){
				s-=a[i-1]-a[i-dp[i]-j+1];
			}	
		}
		ans=max(ans,max(dp[i],dp[i-1]));
	}
	cout<<ans;
}
