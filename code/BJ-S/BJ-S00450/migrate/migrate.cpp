#include<bits/stdc++.h>
using namespace std;
int q,w,e;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>q>>q>>w;
    if(w>4)
    {
        e=1;
    }
    for(int i=1;i<=q;i++)
    {
        cout<<i-e<<endl;
    }
    return 0;
}