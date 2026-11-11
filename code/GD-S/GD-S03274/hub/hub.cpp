#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	int n,k;
	while(t--){
		cin>>n>>k;
		cout<<n*t%k+n<<'\n';
	}
	return 0;
}
