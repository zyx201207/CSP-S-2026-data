#include<bits/stdc++.h>
using namespace std;
string a1,s1,a2,s2;
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2) 
	{
		cout<<'1';
		char a=s1[0],b=s1[1],c=s2[0],d=s2[1];
		if(a==c&&b==d)
		{
			cout<<'1';
			char e=s1[2],f=s2[2];
			if((e=='A'||e=='B'||e=='C')&&(f=='A'||f=='B'||f=='C'))
			{
				cout<<'1';
				if(e+1==f||e-1==f) cout<<'1';
				else cout<<'0';
			}
			else if((e=='D'||e=='F')&&(f=='D'||f=='F'))
			{
				cout<<"11";
			}
			else 
			{
				cout<<"00";
				return 0;
			}
		} 
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else cout<<"0000";

	return 0;
}


