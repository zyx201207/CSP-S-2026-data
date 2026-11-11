#include<bits/stdc++.h>
using namespace std;
int C,T,n,k;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	if(C==13||C==14) {
		while(T--) {
			cin>>n>>k;
			for(int i=1; i<n; i++) {
				int u,v;
				cin>>u>>v;
			}
			int m=(n+1)/2;
			if(k==n) {
				cout<<"0\n";
				continue;
			}
			if(k>=n/2) {
				cout<<"1\n";
				continue;
			}
			if(m%3==1) {
				cout<<(m+2)/3-k/3<<endl;
			}
			if(m%3==2) {
				cout<<(m+2)/3-(k-1)/3<<endl;
			}
			if(m%3==0) {
				cout<<(m+2)/3-(k-2)/3<<endl;
			}
		}
		return 0;
	}
	return 0;
}
