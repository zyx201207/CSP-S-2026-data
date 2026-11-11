#include <bits/stdc++.h>
using namespace std;
int n,c,t,d;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cout<<n%3;
	}
	return 0;
}
