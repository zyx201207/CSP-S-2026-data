#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long len,sum[200005],cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        len+=a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int i=1,j=n,k=a[i],l=a[j];
    while(i<j)
    {
        if(k==l)
        {
            if(c[i]!=c[j])
            {
                cnt+=k;
            }
            i++,j--,k=a[i],l=a[j];
        }
        else if(k>l)
        {
            if(c[i]!=c[j])
            {
                cnt+=l;
            }
            k-=l,j--,l=a[j];
        }
        else
        {
            if(c[i]!=c[j])
            {
                cnt+=k;
            }
            l-=k,i++,k=a[i];
        }
    }
    printf("%lld",cnt);
    return 0;
}