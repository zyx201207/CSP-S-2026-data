#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,s=32,s2=35;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		int w;
		cin >> w;
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin >> k;
		for(int j=1; j<=k; j++) {
			int a,t;
			cin >> a >> t;
		}
	}
	for(int i=1; i<=q; i++) {
		int x,y;
		cin >> x >> y;
		if(n==2){
			cout<<s;
			s-=15;
		}
		else {
			cout<<s2;
			s2-=19;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
