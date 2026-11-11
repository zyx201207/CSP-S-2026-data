#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans,d,b[500001],f[500001];
bool p=true;
int main()
{

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2) d=a[2]-a[1];
        if(i>2 && a[i]-a[i-1]!=d && p) p=false;
    }
    if(p)
    {
        long long t=d;
        for(long long i=m;i>=t&&ans<n;i-=t)
        {
            ans++;
            t+=d;
        }
    }
    if(m==0)
    {
        sort(a+1,a+1+n);
        long long t=0;
        for(long long i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                t++;
                ans=max(ans,t);
            }
            else t=0;
        }
    }
    else
    {
        sort(a,a+1+n);
        for(long long i=1;i<n;i++)
        {
            b[i]=a[i+1]-a[i];
        }
        for(long long i=1;i<n;i++)
        {
            long long t=m,k=i,sum=1,pre=0;
            while(t>=pre+b[k]&&k>0)
            {
                sum++;
                t-=pre+b[k];
                pre+=b[k];
                k--;
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}