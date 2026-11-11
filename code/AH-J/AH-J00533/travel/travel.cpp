#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int i,j,n,m,s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(0)
	//cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) 
	{
		cout<<1;
		for(i=0;i<2;i++)
		{
			if(b[i]!=d[i]) s=1;
		}
		if(!s) 
		{
			cout<<1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))
			{
				cout<<1;
				if(b[2]-d[2]==1||d[2]-b[2]==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
}
