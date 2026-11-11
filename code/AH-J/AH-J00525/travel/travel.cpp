#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,st;
	int a,b;
    string e,j;
    cin>>s>>a>>e>>st>>b>>j;
	if(s!=st)cout<<0<<0<<0<<0<<endl;
	else if(s==st)
	{
        cout<<1;
        if(a!=b)cout<<0<<0<<0<<endl;
        else if(a==b)
        {
            cout<<1;
            if(e<="C"&&j<="C")
            {
				cout<<1;
				if(e=="B"||j=="B")cout<<1<<endl;
				else cout<<0<<endl;
			}
			if(e>="D"&&j>="D")
            {
				cout<<1<<1<<endl;
			}
			if((e<="C"&&j>="D")||(j<="C"&&e>="D"))cout<<0<<0<<endl;
        }
	}
	return 0;
}
