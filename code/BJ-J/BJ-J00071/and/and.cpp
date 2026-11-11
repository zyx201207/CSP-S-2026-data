#include<bits/stdc++.h>
using namespace std;
int n,a[200005],maxx=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]&a[j]>maxx)
            {
                maxx=a[i]&a[j];
            }
        }
    }
    cout<<maxx;
}