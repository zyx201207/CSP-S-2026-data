#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N],lst[N];
int p[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		p[i]=1;
		cin>>a[i];
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=p[i];
		p[lst[a[i]]+1]+=p[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
