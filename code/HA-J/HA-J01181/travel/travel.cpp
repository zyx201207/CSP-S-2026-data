#include <iostream>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	int flag=4;
	cin>>a1>>a2>>b1>>b2;
	char a3=a2[2],b3=b2[2];
	int p1=(a2[0]-'0')*10+(a2[1]-'0');	
	int p2=(b2[0]-'0')*10+(b2[1]-'0');
	if(a1==b1)
	{
		cout<<1;
		flag--;
		if(p1==p2)
		{
			cout<<1;
			flag--;
			if((a3>='A'&&a3<='C'&&b3>='A'&&b3<='C')||(a3>='D'&&a3<='F'&&b3>='D'&&b3<='F'))
			{
				cout<<1;
				flag--;
				if(char(a3+1)==b3||char(a3-1)==b3)
				{
					cout<<1;
					flag--;
				} 
			}
		}
	}
	for(int i=1;i<=flag;i++)cout<<0;
	return 0;
} 
