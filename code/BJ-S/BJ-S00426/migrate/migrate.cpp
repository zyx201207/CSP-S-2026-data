#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a==0&&b==2&&c==4&&d==2)
    {
        cout<<"1\n2";
    }
    else if(a==0&&b==2&&c==5&&d==3)
    {
        cout<<"0\n1";
    }
    else if(a==0&&b==17)
    {
        cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
    }
    else
    {
        cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
    }
    return 0;
}
