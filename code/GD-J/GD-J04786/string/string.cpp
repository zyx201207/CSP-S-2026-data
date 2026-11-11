#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int k=1;k<=n;k++)
        cin>>a[k]>>c[k];
    long long fi=0,cnt=0;
    int l=0;
    for(int i=1;i<=n;i++)
        cnt=cnt+a[i];
    long long mid=(cnt+1)/2,ans=mid,s=0;
    while(fi<=mid)
    {
        fi=fi+a[l+1];
        l++;
    }
    int i=1;
    int j=n-i+1;
    while(i<l&&j>l)
    {
        j=n-i+1;
        if(a[i]==a[j])
        {
            s=s+a[i]-a[j];
            if(c[i]==c[j])
                ans=ans-a[j];
        }
        else if(a[i]+s>a[j])
        {
            s=s+a[i]-a[j];
            if(c[i]==c[j])
                ans=ans-a[j];
        }
        else if(a[i]+s<a[j])
        {
            if(c[i]==c[j])
                ans=ans-a[i];
            s=s+a[j]-a[i];
        }
        if(s==0)
            i++;
    }
    if(s!=0)
        if(c[i]==c[j])
            ans=ans-s;
    if(ans==mid)
        cout<<0;
    else
        cout<<ans;
    return 0;
}

