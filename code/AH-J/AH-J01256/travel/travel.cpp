#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		char a=s1[0],a2=s1[1],b=s2[0],b2=s2[1];
		if(a==b&&a2==b2)
		{
			cout<<1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
			{
				cout<<1;
				if(s1[2]>='A'&&s1[2]<='B'&&s2[2]>='A'&&s2[2]<='B')
				{
					cout<<1;
				}else if(s1[2]>='B'&&s1[2]<='C'&&s2[2]>='B'&&s2[2]<='C')
				{
					cout<<1;
				}else
				{
					cout<<0;
				}
			}else if(s1[2]=='D'&&s2[2]=='F')
			{
				cout<<11;
			}else if(s1[2]=='F'&&s2[2]=='D')
			{
				cout<<11;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
