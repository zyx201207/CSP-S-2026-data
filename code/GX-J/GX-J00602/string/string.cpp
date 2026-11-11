#include<bits/stdc++.h>
using namespace std;
int main( )
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    cin>>n>>a;
    for(int i=1;i<=n;i++)
    {
        if(i==a)
        {
            cout<<"2";
        }
        else
        {
            cout<<"0";
        }
    }
}
