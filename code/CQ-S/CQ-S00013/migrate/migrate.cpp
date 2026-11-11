#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
关注592080谢谢喵！

预计100+100+56+15=271pts

15:13 看题
15:15 吃果冻，零食-1，当前余2
15:16 猪得到一些性质
1.目标对可翻译为：寻找一个二元对(a,b)，使得x->a,x->b,a->y,b->y都仅有一条最短路且x->a+a->y=x->b+b->y
15:20 好吧好像是废话
15:22 试图写一个O(n^3)，性质：从x跳2步等价于从x跳1步的点集再跳1步，且询问方向不重要
dp[i][j] 表示从i开始向后跳j步的点集
转移为
dp[i][j+1]=
for (auto u:dp[i][j]) 
    edge[u]
15:29 好糖啊，我为啥要这么写，修改一下
15:33 O(n^2)写完了
15:35 不对，调一下
15:38 对了，似乎可以优化
15:41 好吧没用，暂时40pts goto->hub看一下
15:50 我回来了，这一世我将找回我的一切
15:58 完全没思路，写点性质分
16:07 我怎么把等比数列当等差了，气死我了
16:28 嘶，这个范围好像CDQ分治，我要思考一下
16:38 得到一个（看上去）相当有用的性质：一个目标对中一定只有一个4元组走法为2，其他的都为1（感觉显然易证）
同时走法为1的部分一定是一个子串（易证）
x->x1->...->a->b->d->y1->y2->...->y
x->x1->...->a->c->d->y1->y2->...->y
问题变为求有多少个四元组(a,b,c,d)满足条件（走法为1的串非常显然是O(n)求）
16:55 这个性质不完全对，但我大概知道他该怎么对了
17:10 我已完全胜利，开始写正解
17:25 草，只有72，将就吧
18:10 完蛋了，调不出来，56跑路了
*/

// int merge(int l,int r)
// {
//     if (l>=r)
//         return 0;
//     const int mid=(l+r)>>1;
//     int res=merge(l,mid);
//     res+=merge(mid+1,r);
//     for (int i=l;i<=mid;i++)
// }

int c;

void solve()
{
    int n,d;
    cin>>n>>d;

    vector<int> a(n+2);
    for (int i=1;i<=n;i++)
        cin>>a[i];

    if (n<=5000)
    {
        vector<vector<int>> edge(n+1);
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n&&a[j]-a[i]<=d;j++)
                edge[i].emplace_back(j);

        int ans=0;
        for (int i=n;i>=1;i--)
        {
            queue<int> q;
            q.emplace(i);
            vector<int> dis(n+1,-1),cnt(n+1);
            dis[i]=0;
            cnt[i]=1;
            while (!q.empty())
            {
                int u=q.front();
                q.pop();

                for (auto v:edge[u])
                {
                    if (dis[v]==-1)
                    {
                        dis[v]=dis[u]+1;
                        cnt[v]=cnt[u];
                        q.emplace(v);
                    }
                    else if (dis[v]==dis[u]+1)
                        cnt[v]+=cnt[u];
                }
            }
            for (int j=i+1;j<=n;j++)
                ans+=(cnt[j]==2);
            // for (int j=i+1;j<=n;j++)
            //     cerr<<cnt[j]<<' ';
            // cerr<<'\n';
        }
        cout<<ans;
        return ;
    }
    if (c>=11&&c<=12)
    {
        int pos=0;
        for (int i=4;i<=n;i++)
            if (a[i]-a[1]>d&&a[i-1]-a[1]<=d&&a[i-2]-a[1]<=d)
            {
                pos=i-1;
                break;
            }
        cout<<(!pos?0:n-(2*pos-1)+2);
        return ;
    }
    
    a[n+1]=a[0]=0x3f3f3f3f3f3f3f3f;
    vector<int> pre(n+1);
    for (int i=1;i<=n;i++)
    {
        int now=i,l=1,r=i,pos=i;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (a[now]-a[mid]<=d)
            {
                pos=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        pre[i]+=i-pos+1;
        if (pos==i)
            continue;
        now=pos;
        while (now>1)
        {
            l=1,r=now-1,pos=0;
            while (l<=r)
            {
                int mid=(l+r)>>1;
                if (a[now]-a[mid]<=d)
                {
                    pos=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            if (!pos)
                break;
            int res=pos;
            l=pos,r=now-1;
            while (l<=r)
            {
                int mid=(l+r)>>1;
                if (a[now+1]-a[mid]<=d)
                {
                    pos=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            pre[i]+=pos-res;
            now=res;
        }
    }
    
    // for (int i=1;i<=n;i++)
    //     cerr<<pre[i]<<' ';
    // cerr<<'\n';

    vector<int> edn(n+2);
    for (int i=1;i<=n;i++)
    {
        int now=i,l=i,r=n,pos=i;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (a[mid]-a[now]<=d)
            {
                pos=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        edn[i]+=pos-i+1;
        if (pos==i)
            continue;
        now=pos;
        // cerr<<"!?"<<i<<' '<<pos<<'\n';
        while (now<n)
        {
            l=now+1,r=n,pos=0;
            while (l<=r)
            {
                int mid=(l+r)>>1;
                if (a[mid]-a[now]<=d)
                {
                    pos=mid;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            // cerr<<"!?"<<i<<' '<<pos<<'\n';
            if (!pos)
                break;
            int res=pos;
            l=now+1,r=pos;
            while (l<=r)
            {
                int mid=(l+r)>>1;
                if (a[mid]-a[now-1]<=d)
                {
                    pos=mid;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            edn[i]+=res-pos;
            now=res;
        }
    }
    
    // for (int i=1;i<=n;i++)
    //     cerr<<edn[i]<<' ';
    // cerr<<'\n';

    int ans=0;
    for (int i=1;i<=n-3;i++)
    {
        int l=i+2,r=n,pos=0;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (a[mid]-a[i]<=d)
            {
                pos=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        // cerr<<"!"<<pos<<'\n';
        if (!pos)
            continue;
        l=pos+1,r=n;
        int res=0;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (a[mid]-a[pos-1]<=d)
            {
                res=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        if (!res||a[res]-a[pos-2]<=d)
            continue;
        // cerr<<"?"<<i<<' '<<res<<'\n';
        int x=i,y=res;
        l=res,r=n;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (a[mid]-a[pos]<=d)
            {
                y=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        l=1,r=i;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (a[pos-1]-a[mid]<=d)
            {
                x=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        // cerr<<"!!!"<<x<<' '<<y<<'\n';
        ans+=pre[x-1]*edn[y+1]+1;
    }
    cout<<ans;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

signed main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef LOCAL
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
    #endif

    int T=1;
    cin>>c>>T;

    while (T--)
    {
        solve();
        if (T)
            cout<<'\n';
    }
    return 0;
}