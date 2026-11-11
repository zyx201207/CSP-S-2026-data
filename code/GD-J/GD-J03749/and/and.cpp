#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
vector<int>s,p;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],s.push_back(i);
	for(int i=30;i>=0;i--){
		p.clear();
		for(int x:s)
			if(a[x]>>i&1)p.push_back(x);
		if(p.size()>=m)ans|=(1<<i),swap(s,p);
	}
	cout<<ans;
	return 0; 
}
