#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
#define maxm 300005
int ans[maxm],a[maxn],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	mt19937 rnd(time(0));
	for(int i=1;i<=m;i++) ans[i]=rnd()%n;
	ans[a[n]]=n;
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
