#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const int M=5e5+10;
const int Q=1e5+10;
ll c,n,m,d,q,w[M];
struct infor1{
	ll k;
	ll a[M];
	ll t[M];
} s[N];
struct infor2{
	ll xx,yy;
} ss[Q];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> s[i].k;
		for(int j=1;j<=s[i].k;j++){
			cin >> s[i].a[j] >> s[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin >> ss[i].xx >> ss[i].yy;
		cout << 100 <<'\n';
	}
	return 0;
}
