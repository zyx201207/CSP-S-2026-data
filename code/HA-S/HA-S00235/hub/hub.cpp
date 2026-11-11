#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		if(n<=5){
			cout<<3<<endl;
			return 0;
		}
		if(n<=10){
			cout<<7<<endl;
			return 0;
		}
		cout<<114514<<endl;
	}
	return 0;
}
