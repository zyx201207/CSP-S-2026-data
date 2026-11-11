#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+3;
ll n,m,ans,fa[N];
struct Node{
	ll pos,num;
}a[N];
inline bool cmp(Node x,Node y){return x.num>y.num;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&fa[i]),a[i]={i,fa[i]};
	ll bj=n,bi=1;
	for(int i=1;i<=31;i++)bi*=2;
	for(int i=30;i>=0;i--){
		sort(a+1,a+bj+1,cmp);
		int l=1,r=bj;bi/=2;
		while(l<r){
			int mid=(l+r+1)/2;
			if(a[mid].num>=bi)l=mid;
			else r=mid-1;
		}
		if(l>=m)bj=l;
		for(int j=1;j<=bj;j++)if(a[j].num>=bi)a[j].num-=bi;
	}
	ll res=fa[a[1].pos];
	for(int i=2;i<=m;i++)res&=fa[a[i].pos];
	printf("%lld",res);
}
