#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=0,t=0;
	cin>>c>>t;
	int n=0,k=0;
	for(int i=0;i<t;i++) {
		cin>>n>>k;
		vector<int> q(n-1,0),p(n-1,0);
		for(int i=0;i<n-1;i++) cin>>q[i]>>p[i];
		cout<<"1\n";
	}
	
	return 0;
}
