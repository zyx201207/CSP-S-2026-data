#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
        if(b[a[i]]==2)
        {
            cout<<a[i];
            return 0;
        }

    }

    return 0;
}
