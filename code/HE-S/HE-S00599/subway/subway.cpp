#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
vecter<int> s[N];
vecter<int> g[N];
int w[N]
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin >> a> t;
			s[i].push_back(a);
			g[i].push_back(t);
		}
	}
	return 0;
}
