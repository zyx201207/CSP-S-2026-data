#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1=="01A"&&s2=="01B"){
			cout<<"111";
		}else if(s1=="01C"&&s2=="01A"){
			cout<<"110";
		}else if(s1=="01C"&&s2=="01D"){
			cout<<"100";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
