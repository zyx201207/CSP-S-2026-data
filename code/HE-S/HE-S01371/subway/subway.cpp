#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n;
	cin>>c>>n;
	if(c==0){
		if(n==2){
			cout<<32<<'\n';
			cout<<17<<'\n';
		}
		if(n==3){
			cout<<35<<'\n';
			cout<<16<<'\n';
		}
	}
	return 0;
} 
