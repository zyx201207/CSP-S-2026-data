#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max1=0;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<m;i++)
    {

        b[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=0;j<m;j++)
        {
            b[j]=max(a[i],b[j]);
        }
    }
    for(int i=1;i<m;i++)
    {
        max1=max(b[i],b[i-1]);
    }
    cout<<max1;
}
