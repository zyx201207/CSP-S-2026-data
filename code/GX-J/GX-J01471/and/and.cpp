#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s=0;
    cin>>n>>s>>m;
    for(int i=1;i<=n;i++)
    {
        if(n>=m)
        {
            s+=n;
        }
        else
        {
            s++;
        }
    }
    cout<<s;
    return 0;
}
