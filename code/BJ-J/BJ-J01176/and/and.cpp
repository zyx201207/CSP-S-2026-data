#include<bits/stdc++.h>
using namespace std;
int a[200005],m;
int cnt[32];
map<int,bool> mp;
int np(int x)
{
    int sum=1;
    for(int i=1;i<=x;i++)
        sum*=2;
    return sum;
}
long long  ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=a[i];
        int j=0;
        while(x)
        {
            cnt[j]+=x%2;
            j++;
            x/=2;
        }
    }
    for(int t=30;t>=0;t--)
    {
        //cout<<cnt[0]<<"\n";
        if(cnt[t]>=m)
        {
            ans+=np(t);
            int f=np(t);
            for(int i=1;i<=n;i++)
            {
                //cout<<mp[a[i]];
                bool ismod=0;
                int x=a[i];
                int j=0;
                if(mp[i])
                    continue;
                //mp[a[i]]=1;
                while(x)
                {
                    if(j==t&&x%2)
                    {
                        ismod=1;
                        break;
                    }
                    if(j>t)
                        break;
                    j++;
                    x/=2;
                }
                if(ismod)
                {
                    continue;
                }
                x=a[i];
                j=0;
                mp[i]=1;
                while(x)
                {
                    cnt[j]-=x%2;
                    j++;
                    x/=2;
                }
            }
            //cout<<"\n";
        }
    }
    cout<<ans;
    return 0;
}
