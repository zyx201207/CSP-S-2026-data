#include<bits/stdc++.h>
#define int long long
#define zsy z1s2y3
using namespace std;
int n,m;
int a[500005],ans[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	set<int> st;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(*st.lower_bound(a[i])==a[i]) {
				st.clear();
			}
			st.insert(a[i]);
		}
		auto x=st.begin();
		while(x!=st.end()){
			ans[*x]++;
			x++; 
		}
		st.clear();
	}
	for(int i = 1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

