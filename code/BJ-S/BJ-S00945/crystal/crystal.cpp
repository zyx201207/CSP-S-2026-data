#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e5+5;
int n;
ll a[N];
ll m;

struct node
{
    ll len;
    ll sum;
};
node dp[N];//dp[i]={a,b}表示以i结尾的符合条件的字串的最大长度(a)，该长度下的和(b)
int d[N];//元素差
int summ[N];
ll ans;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=1)
        {
            d[i]=a[i]-a[i-1];
            summ[i]=summ[i-1]+d[i];
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(dp[i-1].sum+d[i]*(dp[i-1].len+1)<=m)//接着前面的
        {
            dp[i].len=dp[i-1].len+1;
            dp[i].sum=dp[i-1].sum+d[i]*(dp[i-1].len+1);
        }
        else
        {
            //舍去头部的x个元素
            int cur=dp[i-1].sum;//当前的dp字串和
            for(int num=1;num<=dp[i-1].len;num++)
            {
                //当前舍去第i-1-len+num个元素
                //剩余len-num个元素

                //舍去的值：
                ll leave=summ[i-1]-summ[i-1-dp[i-1].len+num-1];
                cur-=leave;
                if(cur+d[i]*(dp[i-1].len-num+1)<=m)
                {
                    //符合条件

                    dp[i].sum=cur+d[i]*(dp[i-1].len-num+1);
                    dp[i].len=dp[i-1].len-num+1;
                    break;
                }
            }
        }
        //cout<<"dp["<<i<<"].len="<<dp[i].len<<" dp["<<i<<"].sum="<<dp[i].sum<<"\n";
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i].len);
    }
    cout<<ans+1;
    return 0;
}