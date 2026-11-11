#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c;
    char b[10],d[10];
    cin>>a>>b>>c>>d;
    if(a!=c)
    cout<<"0000";
    if(a==c)
    {
    	if(b[0]==d[0]&&b[1]==d[1])
		{
			if(b[2]=='A'&&d[2]=='B')
			cout<<"1111";
			if(b[2]=='A'&&d[2]=='C')
			cout<<"1110";
			if(b[2]=='A'&&d[2]=='D')
			cout<<"1100";
			if(b[2]=='A'&&d[2]=='F')
			cout<<"1100";
			if(b[2]=='B'&&d[2]=='A')
			cout<<"1111";
			if(b[2]=='B'&&d[2]=='C')
			cout<<"1111";
			if(b[2]=='B'&&d[2]=='D')
			cout<<"1100";
			if(b[2]=='B'&&d[2]=='F')
			cout<<"1100";
			if(b[2]=='C'&&d[2]=='A')
			cout<<"1110";
			if(b[2]=='C'&&d[2]=='B')
			cout<<"1111";
			if(b[2]=='C'&&d[2]=='D')
			cout<<"1100";
			if(b[2]=='C'&&d[2]=='F')
			cout<<"1100";
			if(b[2]=='D'&&d[2]=='A')
			cout<<"1100";
			if(b[2]=='D'&&d[2]=='B')
			cout<<"1100";
			if(b[2]=='D'&&d[2]=='C')
			cout<<"1100";
			if(b[2]=='D'&&d[2]=='F')
			cout<<"1111";	
		}
		if(b[0]!=d[0]||b[1]!=d[1])
		{
			cout<<"1000";
		}	
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
