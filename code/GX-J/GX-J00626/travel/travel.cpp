#include <bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>n>>m;
    int s,z;
    s=b[2];
    z=b[2];
    if(a==n){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(b[0]==m[0]&&b[1]==m[1])
    {
        cout<<1;
        if(s==65||s==66||s==67)
        {
            if(z==65||z==66||z==67)
            {
                cout<<1;
                if(s==65&&z==66)
                {
                    cout<<1;
                }
                else if(s==66&&z==67||z==65)
                {
                    cout<<1;
                }
                else if(s==67&&z==66)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
        }
        else if(s==68||s==70)
        {
            if(z==68||z==70)
            {
                cout<<1;
                cout<<1;
            }
            else
            {
                cout<<0;
                cout<<0;
            }
        }
        else
        {
            cout<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    return 0;
}
