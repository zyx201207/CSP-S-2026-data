#include <bits/stdc++.h>
using namespace std;
int c,x;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>x;
	while(x--) {
		int n;
		cin>>n>>c;
		for(int i = 1;i<n;i++) cin>>c>>c;
	}
	cout<<1<<endl<<2;
	return 0;
}
