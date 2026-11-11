#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0,a;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        if(n/a==0)
        {
            s++;
        }
        else
        {
            s+=2;
        }
    }
    cout<<s;
    return 0;
}
