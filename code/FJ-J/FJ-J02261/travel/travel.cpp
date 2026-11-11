#include<iostream>
#include<cstring>
#include<string> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			cout<<1; 
			char ch1=s1[2],ch2=s2[2];
			if((ch1=='D'&&ch2=='C')||(ch1=='C'&&ch2=='D'))
			{
				cout<<0<<0;			
			}
			else 
			{
				cout<<1;
				if((ch1-ch2==1)||(ch2-ch1==1))
					cout<<1;
				else
					cout<<0;
			}		
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
