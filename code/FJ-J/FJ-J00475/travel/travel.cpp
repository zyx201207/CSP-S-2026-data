#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	
	if(a==b)
	{
		cout<<"1";
		int k=1;
		for(int i=0;i<x.length()-1;i++)
		{
			if(x[i]!=y[i])
			{
				k=0;
				break;
			}
		}
		if(k==1)
		{
			cout<<"1";
			int c=x[x.length()-1],d=y[y.length()-1];
			if(('A'<=c and c<='C' and 'A'<=d and d<='C') or ('D'<=c and c<='F' and 'D'<=d and d<='F'))
			{
				cout<<"1";
				if('D'<=c<='F' or -1<=d-c and d-c<=1)
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
