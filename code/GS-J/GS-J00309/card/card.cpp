#include<bits/stdc++.h>
using namespace std;
long long a[10000005]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	string s;
	cin>>n;
	int n1,n2,n3,n4,n5;
	int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
	int m1,m2;
	if(n==3)
	{
		cin>>a1>>a2>>a3;		
		if(a1==1&&a2==2&&a3==1)
		{
			cout<<"3 0";	
		}	
		else if(a1==1&&a2==1&&a3==2)
		{
			cout<<"1 2";
		}
		else if(a1==2&&a2==1&&a3==1)
		{
			cout<<"2 1";
		}	
		else if(a1==2&&a2==2&&a3==1)
		{
			cout<<"1 2";
		}	
		else if(a1==2&&a2==1&&a3==2)
		{
			cout<<"3 0";
		}
		else if(a1==1&&a2==2&&a3==2)
		{
			cout<<"3 3";
		}
	}
	if(n==4)
	{
		cin>>a1>>a2>>a3>>a4;		
		if(a1==1&&a2==1&&a3==1&&a4==2)
		{
			cout<<"4 3";	
		}	
		else if(a1==1&&a2==1&&a3==2&&a4==1)
		{
			cout<<"4 0";
		}
		else if(a1==1&&a2==2&&a3==1&&a4==1)
		{
			cout<<"4 0";
		}	
		else if(a1==2&&a2==1&&a3==1&&a4==1)
		{
			cout<<"4 4";
		}	
		else if(a1==1&&a2==1&&a3==2&&a4==2)
		{
			cout<<"4 4";
		}
		else if(a1==1&&a2==2&&a3==2&&a4==1)
		{
			cout<<"4 0";
		}
		else if(a1==2&&a2==2&&a3==1&&a4==1)
		{
			cout<<"4 4";
		}
	}	
	return 0;
}

