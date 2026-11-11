#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		s1=1;
		if(b1[0]==b2[0]&&b1[1]==b2[1])
		{
			s2=1;
			if(b1[2]<='C'&&b2[2]<='C'||b1[2]>'C'&&b2[2]>'C'){
				s3=1;
				if(abs(b1[2]-b2[2])==1)s4=1;
			}
		}
	}
	cout<<s1<<s2<<s3<<s4;
	return 0;
} 
