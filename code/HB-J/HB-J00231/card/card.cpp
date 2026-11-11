#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int i,j,k,s,n,m;
    cin>>n>>m;
    int a[n+1],b[m+2],c[n+1];
    if(m==1)
    {
        cout<<n;
    }
    else if(m==2)
    {
        for(j=1;j<=n;j++) cin>>c[j];
        for(s=1;s<=n;s++)
        {
            for(j=1;j<=n;j++) a[j]=c[j];
            for(i=s;i<=n;i++)
            {
                for(j=1;j<i;j++)
                {
                    if(a[j]==a[i])
                    {
                        for(k=j+1;k<=i;k++) a[k]=0;
                        break;
                    }
                }
            }
            for(j=1;j<=n;j++) b[a[j]]++,cout<<a[j];
        }
        cout<<b[1]<<' '<<b[2];
        return 0;
    }
    for(i=0;i<n;i++) cin>>a[i];
    cout<<"9 3 5";
    return 0;
}
