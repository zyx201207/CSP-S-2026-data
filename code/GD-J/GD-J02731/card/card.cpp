#include <bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for (int i=n;i>=1;i--){
		int j=i;
		while (j<=n){
			ans[a[j]]+=1;
			if (!b[a[j]]){
				b[a[j]]=j;
				j++;
			}
			else
				j=b[a[j]]+1;
		}
	}
	for (int i=1;i<=m;i++)
		cout << ans[i] << " ";
	
	
	return 0;
}
