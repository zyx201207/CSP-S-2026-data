#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int i=1,j=n,k;
    while(i<j)
    {
        if(c[i]!=c[j])
        {
            if(a[i]==a[j])
            {
                ans+=a[i];
                i++;
                j--;
            }
            else if(a[i]>a[j])
            {
                bool flag=false;
                long long sum=0;
                for(k=j;sum<a[i];k--)
                {
                    if(c[k]!=c[i])
                    {
                        if(sum+a[k]>a[i])
                        {
                            ans+=a[k]-sum;
                            a[k]=sum+a[k]-a[i];
                            flag=true;
                            break;
                        }
                        ans+=a[k];
                    }
                    sum+=a[k];
                }
                if(flag)
                    j=k;
                else
                    j=k-1;
                i++;
            }
            else
            {
                bool flag=false;
                long long sum=0;
                for(k=i;sum<a[j];k++)
                {
                    sum+=a[k];
                    if(c[k]!=c[j])
                    {
                        if(sum>a[j])
                        {
                            ans+=a[k]-a[j];
                            a[k]=sum-a[j];
                            flag=true;
                            break;
                        }
                        ans+=a[k];
                    }

                }
                if(flag)
                    i=k;
                else
                    i=k-1;
                j++;
            }
        }
        else
        {
            if(a[i]==a[j]){i++;j--;}
            else if(a[i]>a[j])
            {
                a[i]-=a[i]-a[j];
                j--;
            }
            else
            {
                a[j]-=a[j]-a[i];
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
