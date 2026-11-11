#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
long long n,m,a[MAXN],dp1[MAXN],dp2[MAXN],mm=0,aa;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	for(long long i=1;i<=n;i++){
		dp2[i]=0;
	}
	aa=n;
	for(long long i=2;i<=n;i++){
		dp1[1]=a[i]-a[i-1];
		for(long long j=2;j<i;j++){
			if(j>aa)break;
			dp1[j]=dp2[j-1]+j*dp1[1];
			if(dp1[j]<=m)mm=max(mm,j);
			if(dp1[j]>m){
				aa=j;
				break;
			}
		}
		for(long long j=1;j<=n;j++){
			dp2[j]=dp1[j];
		}
	}
	cout<<mm+1;
	return 0;
}
