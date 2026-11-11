#include<bits/stdc++.h>
#define int long long
#define N 500005
#define M 300005

using namespace std;

int n,m,a[N],la[M],nx[N],bk[N];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = n;i >= 1;i--){
		if(!la[a[i]])nx[i] = i + 1,la[a[i]] = i;
		else nx[i] = la[a[i]];
	}
	for(int i = 1;i <= m;i++){
		int ans = 0;
		for(int j = n;j >= 1;j--){
			if(a[j] == i || bk[nx[j]])bk[j] = 1;
			else bk[j] = 0;
			if(bk[j])ans++;
		}
		cout << ans << " ";
	} 
	return 0;
}
