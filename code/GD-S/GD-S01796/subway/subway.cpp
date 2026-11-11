#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t,n,d,q,m;
	cin>>c>>t>>n>>m>>q;
	while(q--){
		cin>>n>>d;
		cout<<n%4*32+n%7;
	}
	return 0;
}
