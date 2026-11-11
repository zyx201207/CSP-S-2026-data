#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],h=0,ans=0;
char b[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        h+=a[i];
    }
    if(h%2==1)
    {
        int hh=0;
        for(int i=1;i<=n;i++)
        {
            hh+=a[i];
            if(hh>h/2)
            {
                a[i]--;
                break;
            }
        }
        h--;
    }
    for(int i=1,j=n;i<=j;)
    {
        if(b[i]!=b[j])
        {
            if(a[i]!=a[j])
            {
                ans+=min(a[i],a[j]);
                if(a[i]<a[j])
               {
                a[j]-=a[i];
                i++;
               }
               else if(a[i]>a[j])
               {
               a[i]-=a[j];
                j--;
               }
            }
            else
            {
                ans+=a[i];
                i++;
                j--;
            }
        }
        else
        {
            if(a[i]<a[j])
            {
            a[j]-=a[i];
            i++;
            }
            else if(a[i]>a[j])
            {
               a[i]-=a[j];
            j--;
            }
            else if(a[i]==a[j])
            {
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}

