#include <bits/stdc++.h>
using namespace std;
long long n,sum=0,abc[50],ans[50],ward[50];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)
    {

        cout<<0;
        return 0;
    }
    for(long long i=1;i<=30;i++)
    {
        abc[i]=0;
        ans[i]=0;
    }
    long long x,p=0;
    char a;

    for(int i=1;i<=n;i++)
    {
        cin>>x>>a;
        ans[a-'a']+=x;
        p+=x;
        sum+=x;
        ward[i-1]=int(a);
    }
    if(sum%2==0)
    {
        long long mx=-99999;
        for(long long i=0;i<=sum,abc[ward[i]]==0;i++)
        {
            mx=max(ans[ward[i]-int('a')],mx);
            abc[ward[i]]=1;
        }
        if(mx==sum)
        {
            cout<<0;
        }
        else
        {
            cout<<sum-mx;
        }
    }
    else
    {
        long long h=0;
        for(long long i=0;i<=(sum-1)/2-1;i++)
        {

            if(ward[i]!=ward[sum-i-1])
            {
                h++;
            }
        }
        cout<<h;
    }
    return 0;
}
