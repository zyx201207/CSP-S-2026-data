#include <bits/stdc++.h>
using namespace std;
struct node{
	long long v,b;
}a[500005];
int n,ans=0;long long m,dp[500005];
bool cmp(node x,node y){
	return x.v<y.v;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0].v=0;
	for (int i=1;i<=n;i++){
		cin>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) a[i].b=a[i].v-a[i-1].v;
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1]+(a[i].b*(i-1));
		for (int j=1;j<i;j++){
			if (dp[i]-a[i].v+a[j].v<=m) ans=max(ans,i-j+1); 
		}
	}
	cout<<ans;
	return 0;
} 
