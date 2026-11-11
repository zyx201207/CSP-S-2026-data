#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    if(b[0]!=d[0]||b[1]!=d[1])
    {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    int x=b[2]-'A',y=d[2]-'A';
    if((x<=2&&y>2)||(x>2&&y<=2))
    {
        cout<<"00"<<endl;
        return 0;
    }
    cout<<1;
    if(x<=2&&(min(x,y)==0&&max(x,y)==2))
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
}
