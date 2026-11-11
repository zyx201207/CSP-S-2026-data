#include<bits/stdc++.h>
using namespace std;
int k[101];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a1;
	string s,s1;
	cin>>a>>s>>a1>>s1;
	if(a==a1)
	{
		k[1]=1;
		int f=1;
		int n=s.size();
		n--;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=s1[i])
			{
				f=0;
			}
		//	cout<<s[i]<<' '<<s1[i]<<"\n";
		}
		k[2]=f;
		if(f==1)
		{
			if((s[n]=='A'||s[n]=='B'||s[n]=='C')&&(s1[n]=='A'||s1[n]=='B'||s1[n]=='C'))
			{
				k[3]=1;
			}
			if((s[n]=='D'||s[n]=='F')&&(s1[n]=='D'||s1[n]=='F'))
			{
				k[3]=1;
			}
			if(k[3]==1)
			{
				int flag=0;
				if((s[n]=='C'&&s1[n]=='D')||(s[n]=='D'&&s1[n]=='C')) flag=1;
				if(flag==0)
				{
					int id=s[n]-'A';
					int id1=s1[n]-'A';
					if(abs(id-id1)==1) k[4]=1;	
				}
				
			}
		}
		
	}
	for(int i=1;i<=4;i++)
	{
		cout<<k[i];
	}
	return 0;
}
