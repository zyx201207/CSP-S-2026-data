// GZ-J00207 遵义市第四中学 温岳城

#include<bits/stdc++.h>
using namespace std;

constexpr int N=500005,M=300005;
int a[N],cnt[M];bool vis[M];
int main()
{
    // 24pts
    freopen("card.in","r",stdin);freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=5&&m<=2)
    {
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            vector<int> c;
            for(int j=i;j<=n;j++)
            {
                auto it=find(c.begin(),c.end(),a[j]);
                if(it!=c.end()) c.erase(c.begin()+*it,c.end());
                c.push_back(a[j]);
            }
            for(int j=0;j<c.size();j++) if(!vis[c[j]]) cnt[c[j]]++,vis[c[j]]=1;
        }
        for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    for(int i=1;i<=m;i++)
    {
        long long sum=0;
        for(int j=1;j<=i-1;j++) sum+=cnt[j];
        cout<<sum+cnt[i]<<' '; // f**k ccf 小样例错了第四个大样例还全是乱码
    }
    return 0;
}
