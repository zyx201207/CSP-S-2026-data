#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int sn1=s1[2]-'0';
			int sn2=s2[2]-'0';
			char s11=s1[2];
			char s22=s2[2];
			if(s11<='C'&&s11>='A'&&s22<='C'&&s22>='A'||s11<='F'&&s11>='D'&&s22<='F'&&s22>='D'){
				cout<<1;
				if(sn1-sn2==1||sn2-sn1==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
				
			}
			else{
				cout<<0<<0;
			}
			
		}
		else{
			cout<<0<<0<<0;
		}
			
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
	
	
	
	return 0;
}
