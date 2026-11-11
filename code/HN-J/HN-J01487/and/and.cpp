#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
int n,m;
ll a[N];
ll dp[N];
map<ll,int> one;
int f(ll x){
	int ans=0;
	while(x!=0){
		int i=x%2;
		if(i==1) ans++;
		x/=2; 
	}return ans;
}
bool cmp(int x,int y){
	if(one[x]!=one[y]) return one[x]>one[y];
	else return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		one[a[i]]=f(a[i]);
	} 
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++) dp[1]=max(dp[m],a[i]); 
	for(int i=n;i>=1;i--){
		for(int j=2;j<=m;j++){
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}printf("%d",dp[m]);
	return 0;
}


