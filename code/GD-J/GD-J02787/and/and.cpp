#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll a[N],ans;
void dfs(int i,ll a,int num){
	if(num==m){
		ans=max(ans,a);
		return;
	}
	for(int j=i+1;j<=n;j++)dfs(j,a&a[j],num+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a[i]);
	for(int i=1;i<=n;i++)dfs(i,a[i],0);
	cout<<ans;
	return 0;
}
