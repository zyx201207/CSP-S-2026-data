#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b=0,a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a>b)b=a;
    }
    cout<<b;
    return 0;
}
