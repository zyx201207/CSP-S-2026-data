#include<bits/stdc++.h>
using namespace std;
int n,m,z,b=0;
int a[10001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    b=sum/m;
    for(int i=0;i<=n;i++)
    {
        if(a[i]<b)
        {
            z++;
        }
    }
    cout<<z;
    return 0;
}
