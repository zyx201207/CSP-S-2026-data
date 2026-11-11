#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string r2,x2;
int main()
{
	freopen("treval.in","r",stdin);
	freopen("treval.out","w",stdout);
	cin>>r1;
	cin>>r2[1]>>r2[2]>>r2[3];
	cin>>x1;
	cin>>x2[1]>>x2[2]>>x2[3];
	int a=r2[1]*10+r2[2];
	int b=x2[1]*10+x2[2];
	if(r1==x1)
	{
		cout<<1;
		if(a==b){
			cout<<1;
			if(r2[3]=='A'){
				if(x2[3]=='B')
				{
					cout<<1<<1;
				}
				else if(x2[3]=='C')
				{
					cout<<1<<0;
				}
				else
				{
					cout<<0<<0;
				}
			} 
			if(r2[3]=='B'){
				if(x2[3]=='A')
				{
					cout<<1<<1;
				}
				else if(x2[3]=='C')
				{
					cout<<1<<1;
				}
				else
				{
					cout<<0<<0;
				}
			} 
			if(r2[3]=='C'){
				if(x2[3]=='B')
				{
					cout<<1<<1;
				}
				else if(x2[3]=='A')
				{
					cout<<1<<0;
				}
				else
				{
					cout<<0<<0;
				}
			} 
			if(r2[3]=='D'){
				if(x2[3]=='F')
				{
					cout<<1<<1;
				}
				else
				{
					cout<<0<<0;
				}
			} 
			if(r2[3]=='F'){
				if(x2[3]=='D')
				{
					cout<<1<<1;
				}
				else
				{
					cout<<0<<0;
				}
			} 
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}

	return 0;
}
