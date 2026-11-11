#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],sum,ans=(1<<30)-1;
bool f[200005];
vector<int>v[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    //cout<<n<<" "<<m<<"\n";
    sum=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=a[i];
        while(x>0)
        {
            v[i].push_back(x%2);
            x/=2;
        }
        while(v[i].size()<30)v[i].push_back(0);
    }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<v[i].size()<<" ";
        for(int j=29;j>=0;j--)
        {
            cout<<v[i][j];
        }
        cout<<"\n";
    }
    */
    for(int i=29;i>=0;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(f[j])continue;
            if(v[j][i]==0)
            {
                cnt++;
            }
        }
        //cout<<sum<<" "<<cnt<<" "<<i<<"\n";
        if(sum-cnt>m)
        {
            sum-=cnt;
            for(int j=1;j<=n;j++)
            {
                if(f[j])continue;
                if(v[j][i]==0)
                {
                    f[j]=1;
                }
            }
        }
        else if(sum-cnt==m)
        {
            sum-=cnt;
            for(int j=1;j<=n;j++)
            {
                if(f[j])continue;
                if(v[j][i]==0)
                {
                    f[j]=1;
                }
            }
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!f[i])ans&=a[i];
    }
    cout<<ans;
    return 0;
}
