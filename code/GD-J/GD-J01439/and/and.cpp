#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,a[N];
ll ans;
void dfs(int id,int s,ll sum){
	if(s==0){
		ans=max(ans,sum);
		return;
	}
	for(int i=id;i<=n-s+1;i++){
		dfs(i+1,s-1,(sum==0)?a[i]:sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,m,0ll); 
	}
	cout<<ans;

	return 0;
}

