#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+3;
int n,m,a[N],dp;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		int sum=0,ans=1;
		for(int j=i-1;j>=0;j--){
			sum+=a[i]-a[j];
			if(sum<=m)ans++;
			else break;
		}
		dp=max(dp,ans);
	}
	cout<<dp;
	return 0;
}
