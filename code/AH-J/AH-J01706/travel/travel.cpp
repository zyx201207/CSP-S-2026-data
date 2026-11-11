#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	string c1,c2,s1,s2,m;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		m[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			m[1]='1';
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
				m[2]='1';
				if(abs(s1[2]-s2[2])==1)m[3]='1';
				else m[3]='0';
			}
			else {
				for(int i=2;i<4;i++)m[i]='0';
			}
		}
		else {
		for(int i=1;i<4;i++)m[i]='0';
		}
	}
	else {
		for(int i=0;i<4;i++)m[i]='0';
	}
	for(int i=0;i<4;i++)cout<<m[i];
	return 0;
 } 
