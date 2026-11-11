#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,t,t1;
	cin>>s>>s1>>t>>t1;
	if(s==t)
	{
		cout<<1;
		if(s1[0]==t1[0]&&s1[1]==t1[1])
		{
			cout<<1;
			if(t1[2]<='C'&&s1[2]<='C')
			{
				cout<<1;
				if(abs(int(s1[2])-int(t1[2]))==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			 } 
			 else if(t1[2]>='D'&&s1[2]>='D')
			 {
			 	cout<<1;
			 	if(abs(int(t1[2])-int(s1[2]))==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			 }
			 else
			 {
			 	cout<<"00";
			 }
		}
		else
		{
			cout<<"000";
		 } 
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
