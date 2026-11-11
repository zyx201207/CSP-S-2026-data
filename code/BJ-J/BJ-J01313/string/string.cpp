#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],len,b,num,ans,ld[200005],rd[200005];
char c[200005],d;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    m=n;
    while(m--)
    {
        cin>>b>>d;
        len+=b;
        if(d==c[num])
        {
            a[num]+=b;
        }
        else
        {
            a[++num]+=b;
            c[num]=d;
        }
    }
    for(long long i=1;i<=num;i++)
    {
        ld[i]=rd[i-1]+1;
        rd[i]=ld[i]+a[i]-1;
    }
    long long i=1,j=len,l=1,r=num,lmax=len/2,rmin=len-len/2+1;
    while(i<=lmax)
    {
        if(i>rd[l])
        {
            l++;
        }
        if(j<ld[r])
        {
            r--;
        }
        long long t=min(j-ld[r],rd[l]-i);
        if(c[l]!=c[r]) ans+=t+1;
        j-=t;
        i+=t;
        i++;
        j--;
    }
    cout<<ans<<endl;
    return 0;
}
