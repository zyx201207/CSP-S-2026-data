#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m;
long long a[maxn];
long long cnt;
long long cha[maxn];
long long dp[maxn];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		dp[i]=dp[i-1]+cha[i];
	}
	int l=1,r=1;
	cnt=m;
	while(r<=n){
		while(cnt>=0&&r<=n){
			r++;
			if(r>n)break;
			cnt-=(a[r]-a[r-1])*(r-l);
			if(cnt>=0)ans=max(ans,r-l+1);
		}
		if(r>n)break;
		while(cnt<0&&l<=r){
			if(l>=r)break;
			cnt+=dp[r]-dp[l];
			l++;
			if(cnt>=m)ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}
