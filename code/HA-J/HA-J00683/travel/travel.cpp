#include<bits/stdc++.h> 
using namespace std;
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1 1" ;	
		for(int i=1;i<=s1.size();i++)
		{
			for(int j=1;j<=s2.size();j++)
			{
				if(s1[i]==s2[j])
				{
					if(i==j)
					{
						if(s1[i-1]==s2[i-1]||s1[i+1]==s2[j+1])
						{
							cout<<"1";
							if(i==j==3)
							{	
								char t[4]={'A','B','C'};
								for(int i=1;i<=3;i++)
								{
									if(s1[3]==t[i]&&s2[3]==t[i]) 
									{
										cout<<"1";
										if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='B')
										{
											cout<<"1 1";
										}
										else cout<<"0";
									}
									else cout<<"0 0" ;
								}												
				
							}
						}else cout<<"0 0 0";}
					else
					{
						if((s1[i]==s2[j-1]&&s1[i+1]==s2[j])||(s1[i-1]==s2[j]&&s1[i]==s2[j+1]))
						{
							cout<<"1";
							if(i==j==3)
							{	
								char t[4]={'A','B','C'};
								for(int i=1;i<=3;i++)
								{
									if(s1[3]==t[i]&&s2[3]==t[i]) 
									{		
										cout<<"1";								
										if(s1[3]-65==s2[3]-65+1||s1[3]-65==s2[3]-65-1)
										{	
											cout<<"1";			
										}
										else cout<<"0";
									}
								}
								if(s1[3]=='D'||s1[3]=='F')
								{
									for(int i=1;i<=2;i++)
									{
										if(s2[3]=='D'||s2[3]=='F')
										{
											cout<<"1 1";
										}
									}
								}
								else cout<<"0";
							}
							else cout<<"0 0" ;
						}
						else cout<<"0 0 0";	
					}
				
			}
		}
	}
}
else cout<<"0 0 0 0";
} 
