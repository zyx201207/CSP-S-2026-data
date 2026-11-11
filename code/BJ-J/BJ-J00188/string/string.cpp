#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],sum[N];
char c[N];
int main()
{
//    cout<<"www\n";
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        //scanf("%d%c",&a[i],&c[i]);
        //cout<<i<<' ';
        sum[i]=sum[i-1]+a[i];
        if(i==n)
            break;
    }
    int sum1=(sum[n]+1)/2;
    int l=sum1,r=sum1,mr=0;
    if(sum[n]%2==1)
        l--;
    for(int i=1;i<=n;i++)
    {
        if(sum[i]>=sum1)
        {
            mr=i;
            break;
        }
    }
    int ans=0,m=mr;
    while(m>=1 && mr<=n)
    {
        if(c[m]!=c[mr])
        {
            int ls=l-sum[m-1],rs=sum[mr]-r;
            ans+=min(ls,rs);
            if(ls>rs)
            {
                l-=rs;
                r=sum[mr];
                mr++;
            }
            else if(ls<rs)
            {
                r+=ls;
                l=sum[m-1];
                m--;
            }
            else
            {
                l=sum[m-1];
                m--;
                r=sum[mr];
                mr++;
            }
        }
    }
    cout<<ans;
    return 0;
}