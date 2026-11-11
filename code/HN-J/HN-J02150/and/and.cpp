#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],sum,cnt,t[1000005],maxn=-1e9;
void dfs(int s){
	if(cnt>m) return ;
	if(s>n){
		if(cnt==m){
			int f=t[1];
			for(int i=1;i<=cnt;i++){
				f&=t[i];
			}
			maxn=max(maxn,f);
		}
		return ;
	}
	cnt++;
	t[cnt]=a[s];
	dfs(s+1);
	cnt--;
	dfs(s+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<maxn;
	return 0;
}
