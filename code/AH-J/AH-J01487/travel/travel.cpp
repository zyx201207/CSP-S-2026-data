#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int a,b,c,d;
	char e,f;
	cin>>a>>c>>e>>b>>d>>f;
	if(a==b)
	{
		cout<<1;
		if(c==d)
		{
			cout<<1;
			if((f<='C')==(f<='C'))
			{
				cout<<1;
				if(f=='B'||e=='B'||f=='D'||f=='F')
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
