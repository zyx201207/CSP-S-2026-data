
#include<bits/stdc++.h>
#define int long long

using namespace std;
int n,m;
int ans=0;
vector<int> e;

signed main(){
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		e.push_back(a);
	}
	sort(e.begin(),e.end(),greater<int> ());
	while(e[m-1]){
		ans++;
		e[m-1]=(e[m-1]&(e[m-1]-1));
	}
	cout<<ans;
	return 0;
}

