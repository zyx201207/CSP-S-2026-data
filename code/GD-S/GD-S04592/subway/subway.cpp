#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
struct oo{
	int ka,kt;
	int l[500005];
}a[500005];
int w[500005],t[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	while(n--) {
		cin>>k;
		for(int i=1;i<=k;i++) {
			cin>>a[i].ka>>a[i].kt;
		}
	}
	while(q--) {
		int r1,r2;
		cin>>r1>>r2;
		
	} 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
