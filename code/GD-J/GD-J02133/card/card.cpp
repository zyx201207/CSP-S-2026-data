#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],buk[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		vector<int> v;
		int cnt[300005];
		memset(cnt,0,sizeof(cnt));
		for(int j=i; j<=n; j++) {
			if(cnt[a[j]]>=1) {
				while(v.back()!=a[j]&&v.size()>0) v.pop_back();
			} else v.push_back(a[j]);
			cnt[a[j]]++;
		}
		for(int k=0; k<v.size(); k++) buk[v[k]]++;
	}
	for(int i=1; i<=m; i++) cout<<buk[i]<<" ";
	return 0;
}
