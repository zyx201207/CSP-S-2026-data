#include<bits/stdc++.h>
using namespace std;
int dp[200010];
int a[200010];
int sol(int x)//is or no r^k-1
{
    int a=x,cnt=0,cnt1=0;
    while(a)
    {
        if(a&1) cnt1++;
        cnt++;
        a>>=1;

    }
    if(cnt==cnt1) return 1;
    else return 0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //is2^k
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=sol(a[i]);
    }

    //m=2
    int maxx=0;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            maxx=max(maxx,(a[i]&a[j]));
        }
    }
    dp[2]=maxx;

    dp[0]=0;
    //m=n
    int x=a[1];
    for(int i=1;i<=n;i++)
    {
        x=(x&a[i]);
    }
    dp[n]=x;



    //isi-1
    int ansi1=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==i-1) ansi1++;
    }


    if(m==1)
    {
        sort(a+1,a+n+1,greater<int> ());
        cout<<a[1];
        return 0;
    }
    if(m==2)
    {
        cout<<dp[2];
        return 0;
    }
    if(ans==n)//A(a[i]=2^ki-1)
    {
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
        return 0;
    }
    if(ansi1==n)
    {
        int pos=a[n];
        for(int i=n;i>=n-m+1;i--)
        {
            pos&=a[i];
        }
        cout<<pos;
        return 0;
    }
    return 0;
}
