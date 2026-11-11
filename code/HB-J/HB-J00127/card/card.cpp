#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],cnt[N],ans[N];
string s="";
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=(a[i]+'0');
    }
    for(int i=1;i<=n;i++)
    {
        memset(cnt,0,sizeof cnt);
        for(int j=i-1;j<n;j++)
        {
            int t=s.find(s[j],j+1);
            if(t!=-1)
            {
                memset(cnt,0,sizeof cnt);
                j=t;
            }
            cnt[(int)(s[j]-'0')]=1;
        }
        for(int j=1;j<=m;j++)
        {
            ans[j]+=cnt[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
