#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
long long n,a[maxn],cnt;
long long l,r,sum;
char c[maxn];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }

    for(int i=1,j=n; i<=n && j>=1; )
    {
        if(l==0) l+=a[i];
        if(r==0) r+=a[j];

        if(l>r)
        {
            if(c[i]!=c[j])
                cnt+=r;
            l-=r;r=0;j--;
        }
        else if(l<r)
        {
            if(c[i]!=c[j])
                cnt+=l;
            r-=l;l=0;i++;
        }
        else
        {
            if(c[i]!=c[j])
                cnt+=l;
            l=r=0;i++;j--;
        }
    }
    cout<<cnt/2;

    return 0;
}
