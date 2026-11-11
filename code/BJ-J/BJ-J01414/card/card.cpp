#include<bits/stdc++.h>
using namespace std;
int n,a[10000005],m,t[10000005];
string s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<=n;i++)
    {
        s+="a[i]";
        for(int j=1;j<=i;j++)
        {
            if(a[i-j]==a[i])
            {
                s="0";
                s+="a[i]";
                t[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<t[i]<<" ";
    }
    return 0;
}