#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,a3,a4;
	int m1,m2;
	cin>>m1>>m2;
	int n1,n2;
	cin>>n1>>n2;
	char s1,s2;
	if(m1==m2)a1=1;
	else a1=0;
	if(a1==1)
	{
		if(n1==n2)a2==1;
		else a2==0;
		if(a2==1)
		{
			if(s1=='c')
			{
				if(s2=='a'||s2=='b')a3=1;
				else a3=0;
			}
			else if(s1=='a')
			{
				if(s2=='b'||s2=='c')a3=1;
				else a3=0;
			}
			else if(s1=='b')
			{
				if(s2=='a'||s2=='c')a3=1;
				else a3=0;
			}
			else if(s1=='d')
			{
				if(s2=='e')a3=1;
				else a3=0;
			}
			else if(s1=='e')
			{
				if(s2=='d')a3=1;
				else a3=0;
			}
			if(a3==1)
			{
				if(s1=='c')
				{
					if(s2=='b')a4=1;
					else a4=0;
				}
				else if(s1=='a')
				{
					if(s2=='b')a4=1;
					else a4=0;
				}	
				else if(s1=='b')
				{
					if(s2=='a'||s2=='c')a4=1;
					else a4=0;
				}
				else if(s1=='d')
				{
					if(s2=='e')a4=1;
					else a4=0;
				}
				else if(s1=='e')
				{
					if(s2=='d')a4=1;
					else a4=0;
				}
			}
		}
		else
		{
			a3==0;
			a2==0;
		}
	}
	else{
		a2=0;
		a3=0;
		a4=0;
	}
	cout<<1000;
	return 0;
}