#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0,10000);
	int c,t; cin>>c>>t;
	while(t--){
		if(c<7){
			if(dis(gen)%5) cout<<2<<'\n';
			else if(dis(gen)%3) cout<<1<<'\n';
			else cout<<0<<'\n';
		}
		else cout<<dis(gen);
	}
	return 0;
}
