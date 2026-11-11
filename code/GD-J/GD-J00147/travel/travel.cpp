#include<bits/stdc++.h>
#define int long long
#define stp(x) fixed<<setprecision(x)
using namespace std;
string a,b,c,d;
inline int fun(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	else return 2;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(fun(b[2])==fun(d[2])){
				cout<<"1";
				if(abs(b[2]-d[2])==1)cout<<"1\n";
				else cout<<"0\n";
			}else cout<<"00\n";
		}else cout<<"000\n";
	}else cout<<"0000\n";
	return 0;
}
