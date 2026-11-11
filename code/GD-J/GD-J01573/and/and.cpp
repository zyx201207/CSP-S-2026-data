#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,m,a[N],pre,now,t,ans;
bool b[N];
void dfs(int x,int cnt,int num) {
	if(num==m){
		ans=max(ans,cnt);
		return ;
	}
	if(x>n)return ;
	if(num==0){
		dfs(x+1,a[x],num+1);
	}else
	dfs(x+1,cnt&a[x],num+1);
	dfs(x+1,cnt,num);
}
signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	freopen("and.in ","r",stdin);
	freopen("and.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,-1,0);
	cout<<ans;
	return 0;
}
