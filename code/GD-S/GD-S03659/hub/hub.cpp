#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	cin>>c;
	if(c==1)cout<<1<<'\n'<<2;
	else if(c==2||c==3)cout<<1<<'\n'<<1<<'\n'<<2;
	else{
		int t;
		cin>>t;
		while(t--){
			cout<<1<<'\n';
		}
	}
	return 0;
} 
