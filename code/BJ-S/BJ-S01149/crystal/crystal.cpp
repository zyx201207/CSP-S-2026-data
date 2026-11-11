#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],sum,k;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[n];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (sum == m)
        {
            break;
        }
        for(int j=1;j<=n;j++)
        {
            if(sum==m)
            {
                break;
            }
            a[i] += 1;
            if(a[i]==a[j])
            {
                k+=1;
                for(int l=j;l<=m;l++)
                {
                    if(sum==m)
                    {
                        break;
                    }
                    a[j]+=1;
                    if(a[j]==a[l])
                    {
                        for(int b=1;b<=a[l]-a[j];b++)
                        {
                            if(sum==m)
                            {
                                break;
                            }
                            a[i]+=1;
                            sum+=1；
                        }
                        if(sum=!m)
                        {
                            k+=1;
                        }
                        
                    }
                    
                }
            }
            sum+=1;
        }
    }
    cout<<k;
    return 0;
}