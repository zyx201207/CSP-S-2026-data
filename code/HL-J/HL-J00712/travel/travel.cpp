#include <iostream>
using namespace std;
int main(){
	freopen("travel3.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a[5]={0,0,0,0,0};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a[1]=1;
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')==(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
			{
				a[2]=1;
				if(!(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'))
				{
					a[3]=1;
				}
				if(s1[2]=='B'||s2[2]=='B')
				{
					a[3]=1;
				}
				if((s1[2]=='A'&&s2[2]!='C')&&(s2[2]=='A'&&s1[2]!='C')){
					a[3]=1;
				}
			}
		}
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
