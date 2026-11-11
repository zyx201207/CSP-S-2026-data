#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
const int N=5e5+5;
int n,m,a[N],lst[N],fa[N],sz[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=n;i>=1;--i){
		if(lst[a[i]]!=n){
			fa[i]=lst[a[i]]+1;
		}
	}
	for(int i=1;i<=n;++i){
		++sz[i];
		if(fa[i])sz[fa[i]]+=sz[i];
		ans[a[i]]+=sz[i];
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" \n"[i==m];
	}
}