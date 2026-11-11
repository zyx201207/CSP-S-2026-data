#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int b[5000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<n;j++)
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[j])
        {
            for(int k=i;k<=j;k++)
            {
                a[k]=0;
            }
        }
        b[i]++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i];
    }
    return 0;
}
