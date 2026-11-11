#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
set<int> s;
int n,m;
int a[N];
int ans[M];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return;
	}
	for(int T=1;T<=n;T++){
		s.clear();
		for(int i=T;i<=n;i++){
			if(s.count(a[i])==1){
				s.clear();
				s.insert(a[i]);
			}
			s.insert(a[i]);
		}
		for(int i=1;i<=m;i++){
			ans[i]+=s.count(i);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

