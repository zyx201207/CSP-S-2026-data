//T1
#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];

bool cmp(long long x,long long y)
{
    return x>y;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(n<=5000) //1-9
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            long long temp=0;
            for(int j=i+1;j<=n;j++)
            {
                temp+=(a[i]-a[j]);
                if(temp<=m) ans=max(ans,(j-i+1));
                else break;
            }
        }
        cout<<ans;
    }
    else
    {
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(abs(a[i])>100)
            {
                flag=false;
                break;
            }
        }
        if(flag) //10-12
        {
            int negcnt[110],poscnt[110];
            for(int i=1;i<=100;i++)
            {
                negcnt[i]=0;
                poscnt[i]=0;
            }
            poscnt[0]=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]<0) negcnt[-a[i]]++;
                else poscnt[a[i]]++;
            }
            int ans=0;
            for(int i=100;i>=0;i--) //positive
            {
                long long temp=0;
                int cnt=poscnt[i];
                long long tflag=true;
                for(int j=i-1;j>=0;j--)
                {
                    temp+=(poscnt[j]*(i-j));

                    if(temp<=m) cnt+=poscnt[j];
                    else
                    {
                        temp-=(poscnt[j]*((i-j)));
                        temp=m-temp;
                        cnt+=(temp/(i-j));
                        tflag=false;
                        break;
                    }
                }
                if(tflag)
                {
                    for(int j=1;j<=100;j++)
                    {
                        temp+=(negcnt[j]*(i+j));
                        if(temp<=m) cnt+=negcnt[j];
                        else
                        {
                            temp-=(negcnt[j]*((i+j)));
                            temp=m-temp;
                            cnt+=(temp/(i+j));
                            break;
                        }
                    }
                }
                ans=max(ans,cnt);
            }
            for(int i=1;i<=100;i++) //negative
            {
                long long temp=0;
                int cnt=negcnt[i];
                for(int j=i+1;j<=100;j++)
                {
                    temp+=(negcnt[j]*(i-j));
                    if(temp<=m) cnt+=negcnt[j];
                    else
                    {
                        temp-=(negcnt[j]*((i-j)));
                        temp=m-temp;
                        cnt+=(temp/(i-j));
                        break;
                    }
                }
                ans=max(ans,cnt);
            }
            cout<<ans;
        }
        else
        {
            flag=true;
            for(int i=1;i<=n;i++)
            {
                if(a[i]!=i)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) //13-15 A
            {
                long long temp;
                for(int i=n;i>=1;i++)
                {
                    temp=(n+n-i+1)/2.0*i;
                    if(temp<=m)
                    {
                        cout<<i;
                        break;
                    }
                }
            }
            else
            {
                flag=true;
                long long k=a[1]-a[2];
                for(int i=2;i<=n;i++)
                {
                    if((a[i]-a[i-1])!=k)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) //16-18 B
                {
                    long long temp;
                    for(int i=n;i>=1;i++)
                    {
                        temp=(a[n]+a[n-i+1])/2.0*i;
                        if(temp<=m)
                        {
                            cout<<i;
                            break;
                        }
                    }
                }
                else //19,20
                {
                    //?
                }
            }
        }
    }
    return 0;
}
