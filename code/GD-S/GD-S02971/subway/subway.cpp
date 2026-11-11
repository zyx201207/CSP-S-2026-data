#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++){
		cout<<2*d+c+n+m+137891*0+13*i<<"\n";
	}
	
	
	return 0;
}
