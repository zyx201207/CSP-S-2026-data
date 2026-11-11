#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+15;
//const int MOD=;
int a[N],l[N],r[N],n,m,minn=1e9;
int bei[N],cun[N],sum[N],pd[N];
int ans[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){ cin>>a[i];l[i]=r[a[i]],r[a[i]]=i;}
    for(int i=1;i<=m;i++) minn=min(minn,r[i]);
    for(int i=1;i<=n;i++) bei[r[a[i]]]++;
	for(int i=1;i<=n;i++) {bei[i]+=bei[i-1];
		if(r[a[i]]!=i&&i>=minn) bei[r[a[i]]]+=bei[i],bei[i]=0;
		}
    for(int i=1;i<=n;i++){
		if(i==r[a[i]]) cun[a[i]]=bei[i];
	}
	for(int i=1;i<=m;i++) cout<<cun[i]<<' ';
   return 0;
}
//guan zhu luogu cp_zry miao
//shen mi xiao trick,zhe wan yi shi you yi dian
