#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char n,m;
    int a,b,c,d;
    cin>>a>>b>>n>>c>>d>>m;
    //cout<<a<<" "<<b<<" "<<n<<" "<<c<<" "<<d<<" "<<m<<endl;
    if(a==c)
    {
        cout<<1;
        if(b==d)
        {
            cout<<1;
            if((n<='C'&&m<='C')||(n>='D'&&m>='D'))
            {
                cout<<1;
                if(abs((n-m))==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
/*
3
2 a
2 b
1 c
*/
