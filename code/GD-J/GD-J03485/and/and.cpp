#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=2e5+10;
ll n,m,a[maxn],dp[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++) a[i]=i;
	sort(a,a+n,cmp);
	dp[1]=a[0];
	for(ll i=0;i<n;i++){
		for(ll j=2;j<=min(m,i+1);j++){
			if(j==2){
				dp[j]=max(dp[j],max(a[i-1]&a[i],dp[j-1]&a[i]));
				continue;
			}
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}

