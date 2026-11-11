#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],now[N],nex[N],cnt[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i;i--){
		nex[i]=now[a[i]];
		if(!nex[i])nex[i]=i+1;
		now[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		++cnt[i];
		cnt[nex[i]]+=cnt[i];
		ans[a[i]]=max(ans[a[i]],cnt[i]);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
