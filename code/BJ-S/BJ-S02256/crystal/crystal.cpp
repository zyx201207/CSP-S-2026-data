#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum;
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==i) sum++;
    }
    sort(a+1,a+1+n);
    long long y=a[2]-a[1],l=0;
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=y)
        {
            l=1;
            break;
        }
    }
    if(sum==n)
    {
        for(int i=1;i<=n;i++)
        {
            //cout<<(i*i+i)/2<<endl;
            if((i*i+i)/2>m)
            {
                cout<<i<<" ";
                return 0;
            }
        }
    }
    else if(!l)
    {
        cout<<"p";
        long long p=a[2]-a[1];
        long long sum=0,cnt=p;
        for(int i=1;i<=n;i++)
        {
            sum+=cnt;
            cnt+=p;
            if(sum>m)
            {
                cout<<i;
                return 0;
            }
        }
    }
    else
    {
        //cout<<"p";
        long long o=1000000000005,wei;
        for(int i=1;i<=n;i++)
        {
            long long q=0;
            for(int j=1;j<=n;j++)
            {
                q=q+abs(a[i]-a[j]);
            }
            //cout<<q<<" ";
            if(q<o)
            {
                o=q;
                wei=i;
            }
        }
        //cout<<wei<<" ";
        for(long long l=wei-1,r=wei+1;l>=1,r<=n;)
        {
            if(abs(a[wei]-a[l])<=abs(a[wei]-a[r]))
            {
                if(abs(a[wei]-a[l])<=m)
                {
                    m-=abs(a[wei]-a[l]);
                    a[l]=a[wei];
                    l--;
                }
                //cout<<m<<endl;
            }
            
        }
        int lsz=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[wei]) lsz++;
        }
        cout<<lsz;
    }
    return 0;
}
