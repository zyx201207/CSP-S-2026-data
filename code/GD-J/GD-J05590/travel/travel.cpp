#include <iostream>
#include <cmath>
using namespace std;
string c1,s1,c2,s2;
int f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2 and f) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1] and f) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if(((s1[2]-'A'<3 and s2[2]-'A'<3) or (s1[2]-'A'>2 and s2[2]-'A'>2)) and f) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if(abs(s1[2]-s2[2])==1 and f) cout<<1;
	else cout<<0;
	
	
	
	
}
