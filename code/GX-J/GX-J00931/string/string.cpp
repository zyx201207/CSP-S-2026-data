#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005],bj[200005]={0},js=0,ans=0;
    char b[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n/2;i++)
    {
        if(b[i]!=b[n-i+1])
        {
            bj[i]=2;
            js++;
        }
    }
    if(js==0)
    {
        cout<<0;
        return 0;
    }
    else
    {
        for(int i=1;i<=n/2;i++)
        {
            if(bj[i]==2)
            {
                ans+=a[i];
            }
        }

    }
    cout<<ans;
    return 0;
}

