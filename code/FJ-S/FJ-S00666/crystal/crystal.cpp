#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500008],sum[500008];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=a[i]*i-sum[i];
	}
	for(int i=n;i>=1;i--){
		if(sum[i]<=m&&m<=sum[i+1]){
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
} 
/*
5 5
1 2 4  8  9 
0 1 5 17 21
5 8
-3 -1 2 2 7
*/
