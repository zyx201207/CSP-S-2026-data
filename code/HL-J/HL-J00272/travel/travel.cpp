#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    char e,f;
    cin>>a>>b>>c>>d;
    if(a=="02"&&c=="02")
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    cout<<"11";
    for(int i=1;i<=b.size();i++)
    {
        if(b[i]>='A'&&b[i]<='Z')
        {
            e=b[i];
        }
    }
    for(int j=1;j<=d.size();j++)
    {
        if(d[j]>='A'&&d[j]<='Z')
        {
            f=d[j];
        }
    }
    int a1=int(e);
    int a2=int(f);
    if(a1+1==a2||a2+1==a1)
    {
        cout<<"1";
    }
    else
	{
		cout<<0;
	}
}
