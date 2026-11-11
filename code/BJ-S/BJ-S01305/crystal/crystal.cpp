#include<bits/stdc++.h>
using namespace std;
long long a[500005],he[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n;
    long long m;
    cin>>m;
    he[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int y=1;y<=n;y++)
    {
        he[y]=he[y-1]+a[y];
    }
    int pos=-1;
    for(int j=1;j<=n;j++)
    {
        long long sum=j*a[j]-he[j];
        if(sum<=m)
        {
            pos=max(pos,j);
        }
    }
    cout<<pos;
    return 0;
}
