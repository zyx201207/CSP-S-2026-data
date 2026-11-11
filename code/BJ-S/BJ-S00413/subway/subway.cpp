#include<bits/stdc++.h>
using namespace std;
bool vis[500005];
struct node{
    int u;
    int d;
};
int dis[500005];
vector<node> adj[500005];
int w[500005];
map<pair<int,int>,int> t,a;
priority_queue<node> q;
bool operator <(const node &a,const node &b)
{
    return a.d<b.d;
}
void dij(int s)
{
    dis[s]=0;
    q.push({s,0});
    while(!q.empty())
    {
        auto x=q.top();
        q.pop();
        int u=q.top().u,d=q.top().d;
        if(vis[u])
        for(auto y:adj[u])
        {
            int v=y.u,w=y.d;
            if(vis[v]) continue;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main()
{
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        multimap<int,pair<int,int> > cnt;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            a[{i,j}]=x;
            if(cnt.count(x))
            {
                for(auto y:cnt.find(x))
                {
                    int ii=y.second.first,jj=y.second.second;
                    adj.push_back();
                }
            }
            cnt.insert({i,x});
            t[{i,j}]=y;
        }
    }
    return 0;
}
//我被机惨了呜呜呜，考试的时候被自己机惨真是太惨了！
//我居然改了自己的代码还建了文件夹，更可恶的是我居然把考J的同学的文件夹删掉了！
//其实，我想上迷惑性为
//因为我常常追忆过去
//所以我过去常常追忆过去的过去
//所以我过去的过去常常追忆过去的过去的过去
//所以我推出了我在出生时在追忆出生前的事情
//你知道吗，code::blocks里可以打中文哦，感兴趣的小伙伴们可以自行尝试
//我其实只有（8-4*sin 30+1）年级
//所以呢
//我也不知道勒
//哈哈哈
//恭喜你
//你被我恭喜到了
//开心吗？
//好吧，我其实不开心的，因为你没有尝过意大利面拌混凝土炒502，而语文老师说那种东西非常非常的
//好吃
//而语文老师又在从白草原到三维书屋中说过鲁迅小时候的思维是跳跃的
//所以我们可以推导出sin30=1/2
//而且洛谷上昨天距离csp-s考试还有0天
//综合来看，洛谷很有可能就是地理老师说的那种山崖
//而我们知道本次csp考试的题目是四道
//所以综合结论就是code::blocks可以编译c++
//然后，我们就知道了kkk_sc03是一个管理员
//那么，洛谷题目难度最高的就是黑题
//所以，我只吃过一吨的饭菜
//而洛谷每个用户用户至少做过做过32-log2(262144)-2*7道黑题
//那么我们就可以得知在csp-s考场内说出第1题的题面不算泄露题目
//最后的最后，给大家报一下我的洛谷账号吧
//快来膜拜我！
//我们根据此次j,s组的两个密码综合起来就会知道12月25日是圣诞节，不给钱就发射核弹，而老师此时正在怀疑今天是不是十二月二十五日
//终于说完了，感谢您的收听，我们昨天再见
//UID:忘了，明年再打上来
//to 作者：一定要把我说的很要道理的地方加粗哦
