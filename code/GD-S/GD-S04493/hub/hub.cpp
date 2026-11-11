#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=1;i<n;i++)cin>>a>>b;
	cout<<ceil((1.0*(n-m))/3.0)<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll _;
	cin>>_>>_;
	while(_--){
		solve();
	}
	return 0;
}

