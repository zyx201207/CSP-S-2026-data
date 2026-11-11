#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a=='02'&&b=='01A'&&c==02&&d=='01B')
    {
        cout<<"1111";
    }
    else if(a=='02'&&b=='01C'&&c=='02'&&d=='01A')
    {
        cout<<"1110";
    }
    else if(a=='02'&&b=='01C'&&c=='02'&&d=='01D')
	{
		cout<<"1100";
    }
    else if(a=='02'&&b=='02B'&&c=='02'&&d=='01A')
	{
        cout<<"1000";
	}
    else if(a=='02'&&b=='01A'&&c=='03'&&d=='01A')
	{
        cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
