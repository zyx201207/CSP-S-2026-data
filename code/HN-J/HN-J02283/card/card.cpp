#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+5,M=6e5+5;
int n,m,a[N],l[N],mp[M],g[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			mp[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<mp[i]<<" ";
		}
		return 0;
	}
	int u=0;
	for(int i=n;i>=1;i--){
		if(mp[a[i]]==0){
			mp[a[i]]=1;
			l[a[i]]=i;
			u++;
			if(u==m) break;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			g[a[j]]++;
			j=l[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<g[i]<<" ";
	}
	return 0;
}

