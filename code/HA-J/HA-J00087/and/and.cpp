#include<bits/stdc++.h>
using namespace std;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
const int N = 2e5+5;
int n,m,a[N],ans;
vector<int> v,t;
int main(){
	fre("and");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i],v.push_back(i);
	for(int i = 29;i>=0;i--){
		t.clear();
		for(int j = 0;j<v.size();j++){
			int x = v[j];
			if(a[x]&(1<<i)) t.push_back(x);
		}
		if(t.size()>=m){
			v.clear();
			for(int i = 0;i<t.size();i++) v.push_back(t[i]);
			ans+=(1<<i);
		}
	}
	cout << ans;
	return 0;
}
