#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
void solve(){
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
				cout<<"1";
				if(abs((int)b[2]-(int)d[2])==1)	cout<<"1"<<'\n';
				else	cout<<"0"<<'\n';
			}
			else	cout<<"00"<<'\n';
		}
		else	cout<<"000"<<'\n';
	}
	else	cout<<"0000"<<'\n';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	solve();
	return 0;
}
