#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else{cout<<'0';
	}
	string a,b;
	for(int i=0;i<=1;i++)
	{
		a+=s1[i];
		b+=s2[i];
	}
	if(a==b){
		cout<<'1';
		char g,h;
		g=s1[2];
		h=s2[2];
		if(!(g=='C'&&h=='D') && !(g=='D'&&h=='C'))
		{
			cout<<'1';
			if(g-h==1||h-g==1)
			{
				cout<<'1';
			}
			else{
				cout<<'0';
			}
		}
		else{
			cout<<'0'<<'0';
		}
	}
	else{
		cout<<'0'<<'0'<<'0';
	}
	
	
}
