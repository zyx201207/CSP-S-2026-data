#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
set<int> s;
int n,m;
int a[N];
int cnt;
int ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	for(auto i:s){
		a[++cnt]=i;
	}
	ans=a[cnt];
	for(int i=cnt-1;i>=cnt+1-m;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

