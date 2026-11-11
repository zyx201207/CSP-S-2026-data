#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
#define maxm 300005
int n,m,tmp/*,a[maxn]*/,b[maxm],ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d",&tmp);
		b[tmp]++;
	}
	tmp=1;
	while(tmp<=m){
		if (b[tmp]<=0) tmp++;
		for (int i=1;i<=m;i++){
			if (b[i]%2==1) ans[i]++;
		}
		b[tmp]--;
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
