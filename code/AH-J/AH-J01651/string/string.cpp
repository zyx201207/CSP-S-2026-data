#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=1e5+5;
ll a[N];
char c[N];
ll dfs(int l,int r,ll sum1,ll sum2){
	if(l>=r) return 0;
	if(c[l]==c[r]){
		if(sum1<=sum2) return dfs(l+1,r,a[l+1],sum2-sum1);
		else return dfs(l,r-1,sum1-sum2,a[r-1]);
	}else{
		if(sum1<=sum2) return dfs(l+1,r,a[l+1],sum2-sum1)+sum1;
		else return dfs(l,r-1,sum1-sum2,a[r-1])+sum2;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
	} 
	printf("%lld",dfs(1,n,a[1],a[n]));
	return 0;
} 
