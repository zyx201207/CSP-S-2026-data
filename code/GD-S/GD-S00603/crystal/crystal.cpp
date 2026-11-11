#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long s[500001];
long long c[500001];
long long dp[500001];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;long long mn=2147483647,mx=-2147483647;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		mn=min(mn,s[i]);
		mx=max(mx,s[i]);
	}
	s[0]=mn;
	long long delta=mx-mn;
	sort(s+1,s+n+1,cmp);
	c[1]=0;
	for(int i=2;i<=n;i++){
		c[i]=s[i]-s[i-1];
	}
	dp[0]=0;
	int q=1;
	while(c[q]<=m){
		m-=c[q];
		q++;
		ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
