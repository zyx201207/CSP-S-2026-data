#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100053][510],n,m,qzh,me[188888],t[100035][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c>>n >>m>>d >> q;
	for(int i=1;i<=m;i++){
		cin >> me[i];
	}for(int i=1;i<=n;i++){
		int ax;
		cin >> ax;
		for(int j=1;j<=ax;j++){
			cin >> a[i][j];
			cin >>t[i][j];
		}
	}for(int i=1;i<=q;i++){
		int s,e,ans=0;
		cin >>s >> e;
		ans+=me[s];
		ans+=me[e];
		for(int i=1;i<=m;i++){
			if(e==s){ans+=a[i][s];break;}
		}
		cout << ans;
	}
	return 0;
}
