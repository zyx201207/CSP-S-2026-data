#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	int a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]==s2[2])
		a++;
	if(s1[1]==s2[1]&&s1[2]==s2[2])
		b++;
	if(abs(s1[2]-s2[2])==1&&s1[2]!='C'&&s2[2]!='D'&&a==1)
		c++;
	cout<<"1"<<a<<b<<c;
	return 0;
}
