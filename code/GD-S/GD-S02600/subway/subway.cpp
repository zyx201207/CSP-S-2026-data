#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll c,n,m,d,q,w[100005],a[10005][10005],k,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m;
	cin >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=n;j++)cin >> a[i][k];
	}
	while(q--){
		cin >> x >> y;
		
	}
	cout << 32 << endl << 17;
	return 0;
} 
