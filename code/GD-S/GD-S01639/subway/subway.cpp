#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int c,n,m,d,q;
int w[maxn];
vector<pair<int,int>> v[maxn];
map<int,int> mp;
int chose(int l,int r) {
	bool f1=0,f2=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<v[i].size();j++) {
			if(v[i][j].first==l) f1=1;
			if(v[i][j].second==r) f2=1;
		}
		if(f1==1&&f2==1) return 0;
		int f=v[i][1].first;
		for(int j=1;j<=n;j++) {
			if(i==j) continue;
			int fs=v[j][0].first;
			if(f==fs) {
				int mj=v[i][1].second+v[j][0].second;
				return mj+chose(fs,r);
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >>n >> m >> d >> q;
	for(int i=1;i<=m;i++) {
		cin >>w[i];
	} 
	int mxk=0;
	for(int i=1;i<=n;i++) {
		int k;
		cin >> k;
		for(int j=1;j<=k;j++) {
			int a,t;
			cin >> a >> t;
			v[i].push_back({a,t});
		}
	} 
	for(int i=1;i<=q;i++) {
		int l,r,sum=0;
		cin >>l >> r;
		sum=chose(l,r);
		cout << sum<<endl;
	}
	
return 0;
} 
