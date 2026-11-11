#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],cnt[200010][40],vis[200010],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;(1<<j)<=a[i];j++){
			if(a[i]&(1<<j))cnt[i][j]=1;
		}
	}
	for(int i=30;i>=0;i--){
		int res=0;
		vector<int>tmp(n+1);
		for(int j=1;j<=n;j++){
			if(vis[j]||!cnt[j][i])tmp[j]=1;
			else res++;
		}
		if(res>=m){
			for(int j=1;j<=n;j++)vis[j]=tmp[j];
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
