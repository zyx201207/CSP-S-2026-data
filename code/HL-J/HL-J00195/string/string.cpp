#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long len,cnt;
int n,a[2000005],sum[2000005];
char x[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>x[i];
        if(i>=2)
        {
            if(x[i]!=x[i-1])
            {
                f=0;
            }
        }
        for(int j=1;j<=a[i];j++)
        {
            s+=x[i];
        }
        len+=a[i];
        sum[i]+=sum[i-1]+a[i];
    }
    if(f==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        s1[i]=s[len-i-1];
    }
    if(s1==s)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=(n+1)/2;i++)
    {
        if(a[i]>a[n-i+1])
        {
            cnt+=a[i];
            for(int j=sum[n-i+1];j>=sum[n-i];j--)
            {
                s[j-1]=x[i];
            }
        }
        if(a[i]<a[n-i+1])
        {
            cnt+=a[n-i+1];
            for(int j=sum[i];j>=sum[i-1];j--)
            {
                s[j-1]=x[n-i+1];
            }
        }
    }
    s1="";
    int cnt2=0;
    for(int i=0;i<len;i++)
    {
        s1[i]=s[len-i-1];
        if(s[i]!=s1[i])  cnt2++;
    }
    cout<<cnt+cnt2/2;
    return 0;
}
