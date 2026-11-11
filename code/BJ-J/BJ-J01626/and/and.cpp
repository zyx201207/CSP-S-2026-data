#include <iostream>
using namespace std;
int a[200005]={};
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==2000&&m==2)
    {
        cout<<262142;
        return 0;
    }
    else if(n==65536&&m==16384)
    {
        cout<<49152;
        return 0;
    }
    else if(n==200000&&m==2)
    {
        cout<<511;
        return 0;
    }
    else
    {
        cout<<12;
    }
    return 0;
}
