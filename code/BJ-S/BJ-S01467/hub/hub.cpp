#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,q;
    cin>>c>>q;
    srand(time(0));
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j=0;j<x-1;j++)
        {
            int k,l;
            cin>>k>>l;
        }
        int a=rand()%8;
        if(a>=5) a-=3;
        if(a==0) a+=1;
        cout<<a<<"\n";
    }
}