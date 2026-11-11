#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000\n";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000\n";
		return 0;
	}
	string q="";
	q+=s1[2];q+=s2[2];
	if(q=="AB"||q=="AC"||q=="BA"||q=="BC"||q=="CA"||q=="CB"||q=="DF"||q=="FD") cout<<"1";
	else{
		cout<<"00\n";
		return 0;
	}
	
	if(q=="AB"||q=="BA"||q=="BC"||q=="CB"||q=="DF"||q=="FD") cout<<"1";
	else{
		cout<<"0\n";
		return 0;
	}
	cout<<endl;
	
	return 0;
}
