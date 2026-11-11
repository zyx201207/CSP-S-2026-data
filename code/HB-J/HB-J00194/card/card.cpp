#include<bits/stdc++.h>
using namespace std;
#define CuteMushroomBear 50
const int N=5e5+5;
int n,m,a[N],lst[N],pre[N],f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		lst[a[i]]=max(lst[a[i]],i);
	}
	for(int i=1;i<=n;++i){
		++f[i];
		f[i]+=f[pre[a[i]]];
		pre[a[i]]=i;
		if(lst[a[i-1]]==i-1) f[i]+=f[i-1];
	}
	for(int i=1;i<=m;++i) printf("%d ",f[lst[i]]);
	return 0;
}
