#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	//rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		maxx=max(l,maxx);
	}
	cout<<maxx;
	return 0;
}
