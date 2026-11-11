#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[300010];
map<ll,ll> ans;
void play(int start) {
	map<ll,bool> ma;
	vector<ll> ve;
	for(int i=start; i<=n; i++) {
		if(ma[a[i]]!=0) {
			for(int j=ve.size()-1; j>=0; j--) {
				if(ve[j]==a[i])break;
				ma[ve[j]]=0;
				ve.pop_back();
			}
		} else ve.push_back(a[i]);
		ma[a[i]]=1;
	}
	for(int i=0; i<ve.size(); i++) {
		ans[ve[i]]++;
	}
	return ;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for(int i=1; i<=n; i++) {
		cin >>a[i];
	}
	for(int i=1; i<=n; i++) {
		play(i);
	}
	for(int i=1; i<=m; i++) {
		cout <<ans[i]<<" ";
	}
	return 0;
}

