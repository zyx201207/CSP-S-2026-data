#include<bits/stdc++.h>
using namespace std;
int  c, n, m, d, q;
long long a[10000101];
int mian(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++){
		cout<<a[i];
}
	return 0;
}
