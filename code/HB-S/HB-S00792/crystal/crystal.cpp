#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,zx,x,ks=0,jg=0,zd=0,cs=0;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            zx=arr[i];
            x=i;
        }
        if(zx>arr[i])
        {
            zx=arr[i];
            x=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(zx>arr[i]&&cs!=m)
        {
            zx=arr[i];
            zx++;
            x=i;
        }
        arr[x]++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;i++)
        {
            if(zx==arr[j])
            {
                ks++;
            }
            if(ks>=zd)
            {
                zd==ks;
            }
        }
        ks==0;
    }
    cout<<ks;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
