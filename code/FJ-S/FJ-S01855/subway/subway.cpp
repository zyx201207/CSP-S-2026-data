#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k,i,j,s,w[500010],a,t,h[500010],tt;
map<int,map<int,bool> >f;
map<int,map<int,int> >u;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(i = 1;i<=m;i++)cin >> w[i];
	for(i = 1;i<=n;i++){
		cin >> k;
		for(j = 1;j<=k;j++){
			cin >> a >> t;
			tt += t;
			h[j] = a;
			for(s = 1;s<=j;s++){
				f[a][h[s]] = f[h[s]][a] = true;
				u[a][h[s]] = u[h[s]][a] = t;
			}
		}
	}
	for(i = 1;i<=q;i++)cout << tt << endl;
	return 0;
}
