#include <bits/stdc++.h>
using namespace std;
int p[500010],a[500010],t[500010],x[100010],y[100010],k[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> p[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i] >> t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin >> x[i] >> y[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		ans+=p[x[i]]+t[x[i]];
		ans+=p[y[i]]+p[y[i]];
		cout << ans << endl;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
