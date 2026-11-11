#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool a=(c1==c2);
	bool b=a&&(s1[0]==s2[0])&&(s1[1]==s2[1]);
	bool c=b&&((s1[2]<=67&&s2[2]<=67)||(s1[2]>67&&s2[2]>67));//b66 c67 d68
	bool d=b&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'));
	cout<<a<<b<<c<<d;
	return 0;
}
