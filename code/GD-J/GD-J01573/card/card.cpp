#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		map<int,int>mp,val;
		int b[N];
		memset(b,0,sizeof b);
		for(int j=i; j<=n; j++) {
			if(mp[a[j]]) {
				b[mp[a[j]]+1]++;
				b[j]--;
				for(auto e:mp) {
					if(e.second>=mp[a[j]]&&e.second<=j) {
						e.second=0;
						
					}
				}
				mp[a[j]]=j;
			} else {
				mp[a[j]]=j;
			}
		}
		for(int j=i; j<=n; j++) {
			b[j]+=b[j-1];
			if(b[j])continue;
			cnt[a[j]]++;
			cout<<j<<' ';
		}
		cout<<'\n';
	}

	for(int i=1; i<=m; i++) {
		cout<<cnt[i]<<' ';
	}
	return 0;
}/*10 3
3 1 2 1 3 2 3 1 2 1*/
