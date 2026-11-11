//GZ-J00426 ∫Î“„÷–—ß –Ï∫Î”Ó 

#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
long long sum=0;
long long num=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	cin>>c1>>s1>>c2>>s2;
	long long q=s2[2];
	
	if(c1==c2) 
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			cout<<1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C') 
			{
				cout<<1;
				sum++;	
			}
			else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F') 
			{
				cout<<1;
				sum+=2;
			}
			else cout<<0;
	
	
			if(sum==1&&s1[2]+1==q||s1[2]-1==q) cout<<1;
			if(sum==2&&s1[2]+2==q||s1[2]-2==q) cout<<1;
			else cout<<0; 
			
		}
		else 
		{
			cout<<"000"<<"\n";
			return 0;	
		}
	}
	else
	{
		cout<<"0000"<<"\n";
		return 0;
	}
		cout<<"\n";
		return 0;
}

