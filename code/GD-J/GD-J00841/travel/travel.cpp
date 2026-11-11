#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if((b[2]<='c'&&d[2]<='c')){
				cout<<"1";
				if(round(abs(b[2]-d[2]))<=1)cout<<1;
				else cout<<"0";
			}
			else if(b[2]>='d'&&d[2]>='d'){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
