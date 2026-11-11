#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
long long n,m,a[N],dp[N],k[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		long long maxn=0;
		for(int j=m;j>=1;j--){
			k[j]=max(k[j],dp[j]&a[i]);
		}
	}
	cout<<k[m];
	return 0;
}
