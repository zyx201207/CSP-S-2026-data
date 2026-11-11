#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int ans[N];
int cnt[N];
int vis[N];
int lst[N];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	fa[i]=i;
    	cin>>a[i];
    	fa[lst[a[i]]]=i;
    	lst[a[i]]=i;
    	cnt[a[i]]++;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++){
		int j=lst[i];
		while(j<n){
			j=find(j);
			ans[a[j]]+=cnt[i];
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
    return 0;
}
