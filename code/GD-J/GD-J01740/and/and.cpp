#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define x first
#define y second
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
vector<int>v[30];
int n,a[1000005],m;
signed main(){
	fre("and");
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
		rep(j,0,29) if((a[i]>>j)&1) v[j].push_back(a[i]);
	}
	int ans=0;
	for(int i=29;~i;i--) if(v[i].size()>=m){
		ans|=(1<<i);
		rep(j,0,i-1) v[j].clear();
		for(auto o:v[i])
			if((o>>j)&1)
				v[i-1].push_back(o);
	}
	cout<<ans;
}

