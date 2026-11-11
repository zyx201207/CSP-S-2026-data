#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	char c1[10],c2[10],s1[10],s2[10];
	cin>>c1>>s1>>c2>>s2;
	int c11,c22,s11,s22,a1,a2;
	c11=10*(c1[0]-'0')+c1[1]-'0';
	c22=10*(c2[0]-'0')+c2[1]-'0';
	s11=10*(s1[0]-'0')+s1[1]-'0';
	s22=10*(s2[0]-'0')+s2[1]-'0';
	a1=s1[2];
	a2=s2[2];
	
	for(int i=1;i<=1;i++)
	{
		if(c11==c22)
		{
			cout<<1;
			if(s11==s22)
			{
				cout<<1;
			}
			else
			{
				cout<<0<<0<<0;
				break;
			}
			
		}
		else
		{
			cout<<0<<0<<0<<0;
			break;
		}
		
		if((a1<=67||a2<=67)||(a1>=68||a2>=68))
		cout<<1;
		else
		cout<<0;
		
		if(a1-a2==1||a2-a1==1)
		cout<<1;
		else
		cout<<0;
		
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
