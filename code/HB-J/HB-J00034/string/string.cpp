#include <bits/stdc++.h>
using namespace std;
long long l1[200005],l2[200005],tot,t1,t2,ans=0,n,p1,p2;
char s1[200005],s2[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l1[i]>>s1[i];
        l2[n-i+1]=l1[i];
        s2[n-i+1]=s1[i];
        tot+=l1[i];
    }
    t1=t2=ceil(tot/2);
    for(int i=1;i<=n;i++)
    {
        if(l1[i]<=t1)
        {
            t1-=l1[i];
        }
        else
        {
            l1[i]=t1;
            p1=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(l2[i]<=t2)
        {
            t2-=l2[i];
        }
        else
        {
            l2[i]=t2;
            p2=i;
            break;
        }
    }
    for(int i=1;i<=p1;i++)
    {
        for(int j=1;j<=p2;j++)
        {
            if(s1[i]==s2[j])
            {
                if(l1[i]<=l2[j])
                {
                    l2[j]-=l1[i];
                    l1[i]=0;
                    break;
                }
                else
                {
                    l1[i]-=l2[j];
                    l2[j]=0;
                    continue;
                }
            }
            else
            {
                if(l1[i]<=l2[j])
                {
                    l2[j]-=l1[i];
                    ans+=l1[i];
                    l1[i]=0;
                    break;
                }
                else
                {
                    l1[i]-=l2[j];
                    ans+=l2[j];
                    l2[j]=0;
                    continue;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
