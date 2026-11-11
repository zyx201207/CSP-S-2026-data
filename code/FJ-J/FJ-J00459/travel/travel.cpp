#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
string c1,s1,c2,s2;
string ans="0000";
bool l;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string rpai,xpai;
	for(int i=0;i<=1;i++){
		rpai+=s1[i];
		xpai+=s2[i];
	}

	if(c1==c2)ans[0]='1';
	else {
		cout<<"0000"<<'\n';
		return 0;
	}
	
	if(rpai==xpai)ans[1]='1';
	else {
		cout<<"1000"<<'\n';
		return 0;
	}
	
	if(s1[2]<='C'&&s2[2]<='C'){
		ans[2]='1';
	}
	else if(s1[2]>='D'&&s2[2]>='D'){
		ans[2]='1';
		l=1;
	}
	else {
		cout<<"1100\n";
		return 0;
	}

	if(l==0){
		if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
			ans[3]='1';
			cout<<ans<<'\n';
		}
		else cout<<ans<<'\n';
	}
	else {
		if(abs((s1[2]-'D')-(s2[2]-'D'))==1){
			ans[3]='1';
			cout<<ans<<'\n';
		}
		else cout<<ans<<'\n';
	}
	return 0;
}

