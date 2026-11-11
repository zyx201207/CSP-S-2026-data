#include<bits/stdc++.h>
using namespace std;
const int N=500010;
const int M=300010;
typedef long long ll;
#define endl '\n'

int n,m,a[N],f[N],ans[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (register int i=1;i<=n;i++)
		cin >> a[i],f[a[i]]=i;
	for (register int i=n;i>=1;i--){
		int x=f[a[i]];
		ans[a[x]]++;
		while (x!=n){
			if (x<n)
				x++;
			else
				break;
			ans[a[x]]++;
			if (x!=f[a[x]])
				x=f[a[x]];
		}
	}
	for (int i=1;i<=m;i++)
		cout << ans[i] << ' ';
	return 0;
}

