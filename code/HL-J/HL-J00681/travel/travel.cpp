#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,x;
    string r1,x1;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>r1>>x>>x1;
    if(r==x)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(r1[1]==x1[1])
    {
        cout<<1;
        if(r1[2]=='A'&&x1[2]==('B'||'C'))
        {
			if(r1[2]=='B'&&x1[2]==('A'||'C'))
            {
				
				if(r1[2]=='A'&&x1[2]=='B')
				{
					if(r1[2]=='C'&&x1[2]==('B'||'C'))
					{
						cout<<1;
					}
					if(r1[2]=='B'&&x1[2]=='C')
					{
						cout<<1;
					}
				}
				else
				{
					cout<<000;
				}
			}
		}
        if(r1[2]=='D'&&x1[2]=='E')
        {
            cout<<11;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
