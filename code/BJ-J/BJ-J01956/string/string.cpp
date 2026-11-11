#include<bits/stdc++.h>
char c,b[200001];
int n,x,cnt;
long long ans,a[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        std::cin>>x>>c;
        if(c==b[cnt])
        {
            a[cnt]+=x;
        }
        else
        {
            b[++cnt]=c;
            a[cnt]=x;
        }
    }
    for(int i=1,pos=cnt;i<=pos;)
    {
        if(a[i]>a[pos])
        {
            a[i]-=a[pos];
            if(b[i]!=b[pos])
            {
                ans+=a[pos];
            }
            pos--;
        }
        else if(a[pos]>a[i])
        {
            a[pos]-=a[i];
            if(b[i]!=b[pos])
            {
                ans+=a[i];
            }
            i++;
        }
        else
        {
            if(b[i]!=b[pos])
            {
                ans+=a[pos];
            }
            i++;
            pos--;
        }
    }
    std::cout<<ans;
    return 0;
}
