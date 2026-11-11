#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],ans[2000005],mi[2000005],cnt,k;
void solvemi(int x){
	for(int i=x+1;i<=n;i++)if(a[x]+d>=a[i])++k,solvemi(i),mi[i]=min(mi[i],k--);else break;
}
void solve(int x){
	for(int i=x+1;i<=n;i++)if(a[x]+d>=a[i])++k,solve(i),ans[i]+=(k--==mi[i]);else break;
}
signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout),cin>>c>>t;
	while(t--){
		cin>>n>>d,cnt=0;
		for(int i=1;i<=n;i++)scanf("%lld",a+i),mi[i]=INT_MAX;
		solvemi(1),solve(1);
		for(int i=1;i<n;i++)if(a[i]+d<a[i+1])solvemi(i+1),solve(i+1);
		for(int i=1;i<=n;i++)if(ans[i]==2)++cnt;
		cout<<cnt<<"\n";
	}	
	return 0;
}
