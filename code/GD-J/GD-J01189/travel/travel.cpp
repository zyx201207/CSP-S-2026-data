#include<bits/stdc++.h>
using namespace std;
int a1,b1,flag;
string a2, b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1==b1)
	{
		cout << 1; 
		if(a2[0]==b2[0]&&a2[1]==b2[1]) 
	    {
	    	cout<<1;
	    	if(a2[2]<='C'&&b2[2]<'C') 
			{
				cout<<1;
				if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1) cout<<1;
				else cout<<0;
				flag=1;
			}
		    else if(a2[2]>='D'&&a2[2]>='D') 
			{
				cout<<1;
				if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1) cout<<1;
				else cout<<0;
				flag=1;
			}
		    else cout<<0;
		    if(flag==0) cout<<0;
		}
	    else 
		{
			cout<<0<<0<<0;
		}
	}
    else cout<<0<<0<<0<<0;
    
    
    return 0;
}

