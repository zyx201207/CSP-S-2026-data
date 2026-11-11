#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	cout<<n+m+d+q;
	return 0;
}

