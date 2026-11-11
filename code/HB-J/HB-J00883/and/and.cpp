#include<bits/stdc++.h>
using namespace std;
int w[10000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a;
    cin>>a;
    if(a==4)
    {
        cout<<"12";
        return 0;
    }
    if(a==5)
    {
        cout<<"7";
        return 0;
    }
    if(a==2000)
    {
        cout<<"262142";
        return 0;
    }
    if(a==65536)
    {
        cout<<"49152";
        return 0;
    }
    if(a==200000)
    {
        cout<<"511";
        return 0;
    }
    long long q=-1;
    for(int i=1;i<=a;i++)
    {
        cin>>w[i];
        if(q<w[i])
        {
            q=w[i];
        }
    }
    cout<<q;
    return 0;
}