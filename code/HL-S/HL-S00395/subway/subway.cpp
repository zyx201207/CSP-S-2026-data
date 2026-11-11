#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N=5e5+7,M=1e5;
int c,n,m,d,q,k[N],qwer,x[M],y[M];
ll ans;
vector <ll> w;
vector <int> a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	w.push_back(0);
	for(int i=1;i<=m;i++) {
		cin>>qwer;
		w.push_back(qwer);
	}
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		a[i].push_back(0);t[i].push_back(0);
		for(int j=1;j<=k[i];j++) {
			cin>>qwer;a[i].push_back(qwer);
			cin>>qwer;t[i].push_back(qwer);
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>x[i]>>y[i];
	}
//	if(c>=7&&c<=11) {
//		
//	}
	for(int i=1;i<=q;i++) {
		ans=0;
		cout<<x[i]<<' '<<y[i]<<'\n';
		ans+=w[x[i]]+w[y[i]];
		cout<<ans<<'\n';
	}
	return 0;
}