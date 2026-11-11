#include<bits/stdc++.h>
using namespace std;
bool a[200010][35],ans[35];
int cnt[200010];
long long b[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long maxn=0,minn=1e18;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        b[i]=x;
        minn=min(minn,x);
        maxn=max(maxn,x);
        while(x>0)
        {
            a[i][cnt[i]]=x%2;
            x/=2;
            cnt[i]++;
        }
    }
    if(m==1)cout<<maxn<<endl;
    else if(m==n)
    {
        for(int i=1;i<=33;i++)
            ans[i]=a[1][i];
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=33;j++)
                ans[j]&=a[i][j];
        }
        long long an=0;
        for(int i=0;i<=33;i++)
            an+=ans[i]*pow(2,i);
        cout<<an<<endl;
    }
    else if(m==2)
    {
        long long mx=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                {
                    long long t=0;
                    for(int k=0;k<=31;k++)
                        ans[k]=a[i][k];
                    for(int k=0;k<=31;k++)
                        ans[k]&=a[j][k];
                    for(int k=0;k<=31;k++)
                        t+=ans[k]*pow(2,k),ans[k]=0;
                    mx=max(mx,t);
                }
        cout<<mx<<endl;
    }
    else if(maxn<=4)
    {
        int f1=0,f2=0,f3=0,f4=0;
        for(int i=1;i<=n;i++)
            if(b[i]==1)f1++;
            else if(b[i]==2)f2++;
            else if(b[i]==3)f3++;
            else f4++;
        if(f4>=m)cout<<4<<endl;
        else if(f3>=m)cout<<3<<endl;
        else if(f3+f2>=m)cout<<2<<endl;
        else if(f3+f1>=m)cout<<1<<endl;
        else cout<<0<<endl;
    }
    else{
        cout<<minn<<endl;
    }
    return 0;
}