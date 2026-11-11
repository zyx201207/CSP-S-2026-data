#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int n,m;
int a[N];
int dp[N][N];
int ans=0;

int qpow(int n){
	int res=1,x=2;
	while(n>0){
		if(n&1){
			res*=x;
		}
		x=x*2;
		n=n>>1;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int k=log2(n);
	ans=qpow(k-m+1)-1;
	cout<<ans;
    return 0;
}
