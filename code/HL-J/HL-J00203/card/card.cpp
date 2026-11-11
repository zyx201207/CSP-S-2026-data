#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k,j=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1) k=a[i];
        if(k==a[i]) b[j]=b[j]+1;
        else
        {
            j++;
            k=a[i];
            b[j]++;
        }
    }
    int res=0;
    for(int i=1;i<=m;i++)
    {

        res+=b[i];
        cout<<res<<' ';
    }
    return 0;
}
