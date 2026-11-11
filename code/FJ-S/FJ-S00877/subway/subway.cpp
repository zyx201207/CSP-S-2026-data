#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5;
long long c,d,q,n,m,w[M],a[12345];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	long long t=1;
	while(cin>>a[t]){
		t++;
	}
	t=t-1;
	for(int i=t-q*2;i<=t;t+=2){
		cout<<(a[i+1]-a[i])*w[1];
	}
	return 0;
}
