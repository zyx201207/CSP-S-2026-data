#include <iostream>
#include <string>
using namespace std;
#define int long long
string a1,a2,b1,b2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>'C'&&b2[2]>'C')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((a2[2]-'0'+1==b2[2]-'0')||(a2[2]-'0'-1==b2[2]-'0')){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
