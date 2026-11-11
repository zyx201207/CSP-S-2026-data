#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> vt[35];
set<int> st;
int a[200010];
int check(int x){
	int cnt=0;
	for(auto i:vt[x]){
		int y=*st.lower_bound(i);
		if(y==i){
			cnt++;
		}
	}
	return cnt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		for(int j=0;(1ll<<j)<=x;j++){
			if((1ll<<j)&x) vt[j].push_back(i);
		}
		st.insert(i);
	}
	int ans=(1<<30)-1;
	for(int i=32;i>=0;i--){
		if(check(i)<m) continue;
		set<int> x;
		for(auto j:vt[i]){
			int y=*st.lower_bound(j);
			if(y==j){
				x.insert(j);
			}
		}
		st=x;
		if(st.size()==m) break;
	}
	for(auto i:st){
		ans&=a[i];
	}
	cout<<ans;
	
	return 0;
} 
