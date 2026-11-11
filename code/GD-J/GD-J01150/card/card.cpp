#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll num;
	
}tr[3000010];
ll n,m,a[500010],ans[300010],to[500010],f[1010][1010],s[1010][1010],cnt[500010],k;
bitset<300010>had,fact;
ll las[300010];
int main(){
	freopen("card.in" ,"r",stdin );
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n;i>=1;--i){
		if(had[a[i]]){
			to[i]=las[a[i]];
		}else{
//			f[i][a[i]]++;
			to[i]=i+1;
			had[a[i]]=1;
		}
		cnt[i]=1;
		las[a[i]]=i;
//		for(int j=1;j<=m;++j){
//			f[i][j]+=f[to[i]][j];
//		}
//		for(int j=1;j<=m;++j)
//			s[i][j]=s[i+1][j]+f[i][j];
	}
	for(int i=1;i<=n;++i){
		cnt[to[i]]+=cnt[i];
		if(a[to[i]]!=a[i])ans[a[i]]+=cnt[i];
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
/*
10 6
6 4 5 3 2 1 6 1 2 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
