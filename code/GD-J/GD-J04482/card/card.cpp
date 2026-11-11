#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],f,ans[300010],stk[500010],top,vis[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if (a[i]<a[i-1])f=1;
	}
	if (f==0){
		for (int i=1;i<=n;i++){
			ans[a[i]]=max(ans[a[i]],i);
		}
		for (int i=1;i<=m;i++){
		    printf("%lld ",ans[i]);
		}
	}else{
		for (int i=1;i<=n;i++){
			top=0;
			for (int j=i;j<=n;j++){
				for (int k=1;k<=top;k++){
					if (stk[k]==a[j]){
						top=k-1;
						break;
					}
				}
				stk[++top]=a[j];
			}
			for (int j=1;j<=top;j++){
				ans[stk[j]]++;
			}
		}
		for (int i=1;i<=m;i++){
			printf("%lld ",ans[i]);
		}
	}
	return 0;
}
