
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[n],max[n],b;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(a[i]=a[j])
                {
                    max[i]+=1;
                }
                else a[i]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(max[i]<max[i+1])
            {
                b=max[i];
                max[i]=max[i+1];
                max[i+1]=b;
                
            }
        }
    }
    cout<<max[0];
    return 0;
}
