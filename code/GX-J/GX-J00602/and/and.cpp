#include<bits/stdc++.h>
using namespace std;
int main( )
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a,b,c,d;
    cin>>n>>m>>a>>b>>c>>d;
    for(int i=1;i<=n;i++)
    {
        if(a<b)
        {
            cout<<a;
        }
        else if(a<c)
        {
            cout<<"0";
        }
        else if(b==d)
        {
            cout<<"12";
        }
    }
    return 0;
}
