#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m,a[N],b[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++) b[j]=a[j];
		for (int j=i;j<=n;j++){
			int r=n;
			for (;r>j;r--){
				if (b[r]==b[j]){
					j=r;
					break;
				}
			}ans[b[j]]++;
		}
	}for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
