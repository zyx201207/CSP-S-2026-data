#include<bits/stdc++.h>
using namespace std;
char x[100000005];
int a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(long long j=ans;j<=ans+a[i];j++)
        {
            x[j]=b[i];
        }
        ans+=a[i];
    }
    int cnt=0;
    for(int i=1;i<=n/2;i++)
    {
        if(x[i]!=x[n-i+1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
