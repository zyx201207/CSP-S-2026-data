#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t1;
    char t2;
    string a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %c",&t1,&t2);
        for(int j=1;j<=t1;j++)
        {
            a+=t2;
        }
    }
    long long len=a.size(),l=0,ans=0;
    for(int i=len-1;i>=len/2+1;i--)
    {
        if(a[i]!=a[l])ans++;
        l++;
    }
    printf("%lld",ans);
    return 0;
}
