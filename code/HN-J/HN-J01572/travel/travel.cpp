#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	//cout<<s<<endl;
	//cout<<n<<" "<<s1<<" "<<m<<" "<<s2<<endl;
	if(s[0]==s[7]&&s[1]==s[8]) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s[3]==s[10]&&s[4]==s[11]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s[5]>='D'&&s[12]>='D') cout<<"11";
	else if(s[5]<='C'&&s[12]<='C'){
		if(s[5]=='B'||s[12]=='B') cout<<"11";
		else cout<<"10";
	}else cout<<"00";
	return 0;
	//Trick||Treat!
}
