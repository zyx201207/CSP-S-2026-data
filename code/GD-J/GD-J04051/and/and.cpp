#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
int w(int x,int i){return (x>>i)&1;}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;vector<int> g,g2;
	for(int i=1;i<=n;i++) cin>>a[i],g.push_back(i);
	for(int i=30;i>=0;i--) {
		int cnt=0;
		for(int j:g) if(w(a[j],i)) cnt++,g2.push_back(j);
		if(cnt>=m) ans+=(1<<i),g=g2,g2.clear();
	}cout<<ans;
}
