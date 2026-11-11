#include<bits/stdc++.h>
using namespace std;
long long s[500005],n,m,ans,qian[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	sort(s+1,s+n+1); 
	for(int i=1;i<=n;i++){
		qian[i]=qian[i-1]+s[i];
		if(s[i]*(i-1)-qian[i-1]<=m) ans=i;
	}
	printf("%lld",ans);
	return 0;
} 
