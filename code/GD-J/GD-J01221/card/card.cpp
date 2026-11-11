#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
const int M=3e5+5;
int a[N],lst[M];
int vis[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		vis[a[i]]++;
	}for(int i=1;i<=n;i++) ans[a[i]]=vis[a[i]];
	for(int i=1;i<=n;i++){
		if(i-1==lst[a[i-1]]) ans[a[i]]+=ans[a[i-1]];
	}for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<" ";
	}
	return 0;
}
