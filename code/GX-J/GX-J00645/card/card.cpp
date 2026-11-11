#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin)
    freopen("and.our","w",stdour)


    int a[100],m,n,b[100],c[100];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    for(int s=1;s<=n;s++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[j]==a[i])
                {
                    for(int k=i;k<=j-1;k++)
                    {
                        b[k]=0;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}


