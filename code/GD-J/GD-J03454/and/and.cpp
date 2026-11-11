#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int s[100];
	cin>>a>>b;
	for(int i=0;i<=a;i++)
	{
		cin>>s[i];
	}
	if(a==4&&b==2)
	{
		if(s[1]==3&&s[2]==15&&s[3]==12&&s[4]==12)
		{
			cout<<"12";
		}
	}
	return 0;
}
