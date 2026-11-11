#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[1005],s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>m;
        for(int j=1;j<=m;j++)
        {
            if(a[i]==1)
            {
                s++;
            }
            else
            {
                break;
            }
        }
        cout<<s;
    }
    return 0;
}
