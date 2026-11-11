#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a,b;
long long w[500005],k[505],t[500005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(long long i=1;i<=m;i++){
		cin >> w[i];
	}
	for(long long i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a >> b;
			t[a]=b;
		}
	}
	for(long long r=1;r<=q;r++){
		long long s=0,x,y;
		cin >> x >> y;
		s+=w[x];
		s+=w[y];
		s+=t[x];
		s+=t[y];
		cout << s << endl;
	}
	return 0;
}
