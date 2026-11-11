#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int n;
long long m,a[maxn]={0},ch[maxn];
long long dp[maxn]={0},ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ch[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	long long sum;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i-1;j>=1;j--){
			sum+=(a[i]-a[j]);
			if(sum>m) break;
			else dp[i]++;
		}
	}
	for(int i=2;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans+1<<endl;
	return 0;
}
