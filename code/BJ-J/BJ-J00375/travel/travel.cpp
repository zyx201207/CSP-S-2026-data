#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000"<<endl;
    }
    else
    {
        if(b[0]!=d[0]||b[1]!=d[1])
        {
            cout<<"1000"<<endl;
        }
        else
        {
            int x=b[2]-'A',y=d[2]-'A';
            //cout<<x<<' '<<y<<endl;
            if(0<=x&&x<=2&&0<=y&&y<=2||3<=x&&x<=4&&3<=y&&y<=4)
            {
                if(abs(x-y)==1)cout<<"1111"<<endl;
                else cout<<"1110"<<endl;
            }
            else
            {
                cout<<"1100"<<endl;
            }
        }
    }
}