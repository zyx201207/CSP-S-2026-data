#include<bits/stdc++.h> 
using namespace std;
int a[1000000];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x,s,z;
	string t,c;
	char d,f;
	cin>>r>>t>>x>>c;
	for(int i=1; i<=t.size(); i++)
	{
		 if(t[i]<='Z'&&t[i]>='A')
		 {
		 	d=t[i];
		 }
	}
	for(int i=1; i<=c.size(); i++)
	{
		 if(c[i]<='Z'&&c[i]>='A')
		 {
		 	f=c[i];
		 }
	}
	for(int i=1; i<=t.size(); i++)
	{
		 if(t[i]<='9'&&t[i]>='0')
		 {
		 	s=t[i];
		 }
	}
	for(int i=1; i<=c.size(); i++)
	{
		 if(c[i]<='9'&&c[i]>='0')
		 {
		 	z=c[i];
		 }
	}
	if(r!=x)
	{
		cout<<"0"<<"0"<<"0"<<"0";
	 } 
	 else if(r==x)
	 {
	 	cout<<"1";
	 	if(s==z)
	 	{
	  	  cout<<"1";
	 		if(d=='D'&&f=='F'||d=='F'&&f=='D')
	 		{
	 			cout<<"1"<<"1";
			 }
			 else if(d=='A'||d=='B'||d=='C')
			 {
			 	if(f=='A'||f=='B'||f=='C')
			 	{
			 		cout<<"1";
			 		if(d=='A'&&f=='B'||d=='B'&&f=='A'||d=='B'&&f=='C'||d=='C'&&f=='b')
			 		{
			 			cout<<"1";
					 }
					 else
					 {
					 	cout<<"0";
					 }
				 }
				 else
				 {
				 	cout<<"0"<<"0";
				 }
			 }
			   else
		    {
		 	   cout<<"0"<<"0";
		    }
		 }
		 else
		{
		   cout<<"0"<<"0"<<"0";
		}
		 
	 }
	return 0;
}
