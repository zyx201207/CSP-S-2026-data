#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], oo[500005], l=0, ans[500005], id[500005];
int vis[500005];
int b[500005];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int f=0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=1;
	}
	if(!f){
		for(int i = 1; i <= n; i++){
			ans[a[i]]++;
		}
		for(int i = 1; i <= m; i++){
		cout<<ans[i]<<' ';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;id[a[j]]=j;
				b[++l]=a[j];
				if(b[l]==i)ans[i]++;
			}
			else{
				for(int k = id[a[j]]; k <= l; k++)b[i]=0;
				l=id[a[j]]-1;
				vis[a[j]]=0;
			}
		}
		memset(vis, 0, sizeof(vis));
		l=0;
		memset(b, 0, sizeof(b));
		memset(id, 0, sizeof(id));
//		cout<<ans[i]<<"oo\n";
	}
	for(int i = 1; i <= m; i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
