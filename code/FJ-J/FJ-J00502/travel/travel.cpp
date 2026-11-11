#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			cout<<"1";
			char a=s1[2],b=s2[2];
			if(((a=='D'||a=='F')&&(b=='D'||b=='F'))||((a=='A'||a=='B')&&(b=='A'||b=='B'))||((a=='B'||a=='C')&&(b=='B'||b=='C')))
			cout<<"11";
			else{
				if((a=='A'||a=='C')&&(b=='A'||b=='C'))
				cout<<"10";
				else
				cout<<"00"; 
			}
	    }
	    else
	    cout<<"000";
    }
	else
	cout<<"0000";
    return 0;
}
