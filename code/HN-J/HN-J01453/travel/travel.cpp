#include<iostream>
using namespace std;
long long c1,c2;
string s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int s3=(s1[0]-'0')*10+(s1[1]-'0'),s4=(s2[0]-'0')*10+(s2[1]-'0');
		char s5=s1[2],s6=s2[2];
		if(s3==s4){
			cout<<"1";
			if((s5<'D'&s6<'D')||((s5>'C'&s6>'C'))) {
				cout<<"1";
				if(( s5=='C' && s6=='A' ) || ( s6=='C' && s5=='A' )) cout<<"0";
				else cout<<"1";
			}
			else cout<<"00";
		}
		else cout<<"000";
			
	}
	
	else cout<<"0000";
	
	return 0;
}
