#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cin>>c[i];
        mx=max(mx,a[i]);
    }
    if(mx*n>1000000000)
    {
        return 0;
    }
    string s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    int m=s.size();
    long long ans=0;
    for(int i=0;i<m/2;i++)
    {
        if(s[i]!=s[m-i+1])
        {
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
