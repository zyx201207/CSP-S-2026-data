#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int s[10]={c1,s1,c2,s2};
	int a[10]={0,2};
	int b[10]={0,1,'A'};
	int c[10]={0,2};
	int d[10]={0,1,'B'};
	if(a[1]==c[1])
	{
		cout<<"1";
		if(b[1]==d[1])
			cout<<"1";
		else
			cout<<"0";
			if(b[2]&&d[2]>='D'||b[2]&&d[2]<='C')
				cout<<"1";
			else
				cout<<"0";
				if(b[2]+1==d[2])
					cout<<"1";
				else
					cout<<"0";
	}
	return 0;
} 
