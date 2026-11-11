#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int w=1,h=1;
    for(int i=0;i<2;i++)
    {
        if(a[i]!=c[i])
        {
            w=0;
            break;
        }

    }
    if(w==1)
    {
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++)
    {
        if(b[i]!=d[i])
        {
            h=0;
            break;
        }
    }
    if(h==1)
    {
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'))
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(b[2]-1==d[2]||b[2]+1==d[2])
    {
        cout<<1;
    }
    else{
        cout<<0;
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
