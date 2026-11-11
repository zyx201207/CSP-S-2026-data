#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],maxn,ans,cha,ans2,b[100005];
bool f=false;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        //cout<<i<<' '<<a[i]<<"        \n";
    }
    cha=a[2]-a[1];
    for(long long i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=cha)
        {
            f=1;
            break;
        }
    }
    //cout<<"d";
    sort(a+1,a+n+1);
    //cout<<f<<"        \n";
    if(f)
    {
        for(long long i=1;i<=maxn;i++)
        {
            long long m2=m,cnt=0;
            ans=0;
            for(int j=1;j<=n;j++)
            {
                b[i]=0;
            }
            for(int j=1;j<=n;j++)
            {
                if(a[j]>i)
                {
                    break;
                }
                b[++cnt]=i-a[j];
                //cout<<"x";
            }
            //cout<<i<<"   y\n";
            while(cnt>0&&m2>0)
            {
                //cout<<b[cnt]<<' '<<m2<<"\n";
                m2-=b[cnt];
                cnt--;
                ans++;
            }
            //cout<<m2<<"\n";
            if(m2<0)
            {
                ans--;
            }
            //cout<<ans<<"          xx\n";
            ans2=max(ans,ans2);
        }
        cout<<ans2<<"\n";
        return 0;
    }
    long long b=abs(a[2]-a[1]),c=1;
    ans=1;
    while(m>0)
    {
        m=m-b*c;
        c++;
        ans++;
        //cout<<"x";
    }
    if(m<0)
    {
        ans--;
    }
    cout<<min(ans,n)<<"\n";
    return 0;
}
