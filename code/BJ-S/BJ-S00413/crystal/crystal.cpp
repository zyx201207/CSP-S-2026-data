#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    int Aflg=1,Bflg=1,k=0;;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i) Aflg=0;
        if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) Bflg=0;
        k=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    long long res=0,ans=0;
    long long m2=m;
    for(int i=-105;i<=105;i++)
    {
        ans=0;
        m2=m;
        for(int j=n;j>=1;j--)
        {
            if(a[j]==i) ans++;
            if(a[j]<i && m2>=i-a[j])
            {
                m2-=i-a[j];
                ans++;
            }
        }
        //cout<<i<<" result:"<<ans<<"\n";
        res=max(res,ans);
    }
    if(Aflg)
    {
        int r=1;
        for(int i=1;i<=100005;i++)
        {
            if((i+1)*i/2.0<=m*1.0) r=i;
            else if((i+1)*i/2>m) break;
        }
        cout<<r;
    }
    else if(Bflg)
    {
        int r=1;
        for(int i=1;i<=100005;i++)
        {
            if((i+1)*(i)*k/2.0<=m*1.0) r=i;
            else if((i+1)*i/2>m) break;
        }
        cout<<r;
    }
    else cout<<res;
    return 0;
}
