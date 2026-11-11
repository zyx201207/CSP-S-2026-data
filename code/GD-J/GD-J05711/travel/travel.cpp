#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int c1, c2;
	string s1, s2;
	
	cin>>c1>>s1>>c2>>s2;
	
	int b1=(int(s1[0])-int('0'))*10+(int(s1[1])-int('0'));
	int b2=(int(s2[0])-int('0'))*10+(int(s2[1])-int('0'));
	
	char a=s1[2];
	char b=s2[2];
	
	//cout<<a<<" "<<b<<endl;
	
	if(a>b)
	{
		
		swap(a, b);
		
	}
	
	if(c1!=c2)
	{
		
		cout<<"0000";
		return 0;
		
	}
	else
	{
		
		if(b1!=b2)
		{
			
			cout<<"1000";
			return 0;
			
		}
		else
		{
			
			if(a<='C'&&b>='D')
			{
				
				cout<<"1100";
				return 0;
				
			}
			else
			{
				
				if((a+1)!=b)
				{
					
					cout<<"1110";
					return 0;
					
				}
				else
				{
					
					cout<<"1111";
					return 0;
					
				}
				
			}
			
		}
		
	}
	
	return 0;
	
}
