#include<bits/stdc++.h>
#include<cstring>
int a[500005];
int b[500005];
int c[500005];
int k=0;
int d=0;
using namespace std;
int main()
{
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
    int n,m;
    int cnt=1;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            b[k]=a[i];
            k++;
        }
        if(a[i]>=0)
        {
            c[d]=a[i];
            d++;
        }
    }
    return 0;
}
