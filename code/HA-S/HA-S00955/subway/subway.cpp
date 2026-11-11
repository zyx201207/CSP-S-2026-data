#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	long long station[m+5];
	for(int i=1;i<=m;i++){
		cin>>station[i];
	}
	for(int i=1;i<=q;i++){
		long long stat;
		cin>>stat;
	}
	return 0;
}
