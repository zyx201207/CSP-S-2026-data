#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin());
    freopen("string.out","w",stdout());
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[100005];
    char c[100005];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    char s[sum+1];
    int m=0;
    int x=0;
    while(x<=n)
    {
        for(int j=m+1;j<m+a[x]+1;j++)
        {
            s[j]=c[x];
        }
        m=m+a[x];
        x++;
    }
    int p=0;
    for(int i=1;i<=sum;i++)
    {
        if(s[i]!=s[sum+1-i])
        {
            s[i]=s[sum+1-i];
            p++;
        }
    }
    cout<<p;
    return 0;
}
