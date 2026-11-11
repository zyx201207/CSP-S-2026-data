#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int maxx;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			maxx = 0;
			for(int k=j;k<=n;k++){
				if(a[j]==a[k]){
					maxx = max(maxx,k);
				}
			}
			j = maxx;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
