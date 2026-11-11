#include<bits/stdc++.h>
using namespace std;
int a[200010];
string st[200010];
int dp[2][200010];//1->i,choose j,
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],st[i]="";
    sort(a+1,a+n+1);
    int N=a[n],t=0;
    while(N>0)
    {
        t++;
        N/=2;
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i],len=0;
        while(x!=0)
        {
            char y=(x%2+'0');
            st[i]+=y;
            x/=2;
            len++;
        }
        string add="";
        for(int i=1;i<=t-len;i++) add+="0";
        st[i]+=add;
    }
    if(m==1)
    {
        cout<<a[n]<<endl;
        return 0;
    }
    if(m==n)
    {
        int ans=0;
        for(int i=0;i<t;i++)
        {
            bool p=true;
            for(int j=1;j<=n;j++)
                if(st[j][i]=='0')
                {
                    p=false;
                    break;
                }
            if(p==false) continue;
            int cnt=1;
            for(int j=1;j<=i;j++) cnt*=2;
            ans+=cnt;
        }
        cout<<ans<<endl;
        return 0;
    }
    bool p=true;
    for(int i=1;i<=n;i++)
        reverse(st[i].begin(),st[i].end());
    for(int i=1;i<=n&&p==true;i++)
    {
        bool isc=false;
        for(int j=0;j<st[i].size();j++)
        {
            if(st[i][j]=='0'&&isc==true)
            {
                p=false;
                break;
            }
            if(st[i][j]=='1') isc=true;
        }
    }
    if(p==true)
    {
        reverse(st[n-m+1].begin(),st[n-m+1].end());
        int ans=0;
        for(int i=0;i<st[n-m+1].size();i++)
        {
            if(st[n-m+1][i]=='0') break;
            int cnt=1;
            for(int j=1;j<=i;j++) cnt*=2;
            ans+=cnt;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        reverse(st[i].begin(),st[i].end());
    if(m==2)
    {
        int ans=0;
        for(int i=0;i<t;i++)
        {
            bool p=true;
            for(int j=1;j<=n;j++)
            {
                int ans1=0;
                for(int k=1;k<j;k++)
                {
                    if(st[j][i]=='0'||st[k][i]=='0')
                    {
                        p=false;
                        break;
                    }
                    if(p==false) continue;
                    int cnt=1;
                    for(int o=1;o<=i;o++) cnt*=2;
                    ans1+=cnt;
                }
                ans=max(ans,ans1);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    int tep=0;
    dp[1][1]=a[1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<i<<" "<<j<<endl;
            //if(j==1) dp[i%2][j]=a[i]; else
            dp[i%2][j]=dp[(i+1)%2][j];
            int Q=dp[(i+1)%2][j];
            string now="";
            while(Q!=0)
            {
                char y=(Q%2+'0');
                now+=y;
                Q/=2;
            }
            reverse(now.begin(),now.end());//1->n-1,ans(2)
            int ans=0;
            for(int k=min(now.size(),st[i].size())-1;i>=0;i--)
            {
                if(now[k]==st[i][k])
                {
                    int cnt=1;
                    for(int o=1;j<=k;o++) cnt*=2;
                    ans+=cnt;
                }
            }
            if(ans>Q) dp[i%2][j]=ans;
            if(j==m) tep=max(tep,dp[i%2][j]);
        }
    }
    cout<<tep<<endl;
}