#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class SegmentTree
{
    const int size;
    struct Node
    {
        int color=0;
        int lazy=0;
    };
    vector<Node> nodes;
    void push_down(const int now)
    {
        if(nodes[now].lazy!=0)
        {
            nodes[now<<1].color=nodes[now<<1].lazy=nodes[now].lazy;
            nodes[now<<1|1].color=nodes[now<<1|1].lazy=nodes[now].lazy;
            nodes[now].lazy=0;
        }
    }
    void update_range(const int objL,const int objR,const int diff,const int now,const int nowL,const int nowR)
    {
        if(objL<=nowL&&nowR<=objR)
        {
            nodes[now].color=nodes[now].lazy=diff;
        }
        else
        {
            push_down(now);
            const int mid=(nowL+nowR)>>1;
            if(objL<=mid)
            {
                update_range(objL,objR,diff,now<<1,nowL,mid);
            }
            if(objR>mid)
            {
                update_range(objL,objR,diff,now<<1|1,mid+1,nowR);
            }
        }
    }
    int query_point(const int obj,const int now,const int nowL,const int nowR)
    {
        if(nowL==nowR)
        {
            return nodes[now].color;
        }
        else if(nowL<=obj&&obj<=nowR&&nodes[now].color!=0)
        {
            return nodes[now].color;
        }
        else
        {
            push_down(now);
            const int mid=(nowL+nowR)>>1;
            if(obj<=mid)
            {
                return query_point(obj,now<<1,nowL,mid);
            }
            else
            {
                return query_point(obj,now<<1|1,mid+1,nowR);
            }
        }
    }

public:
    SegmentTree(const int si):size(si)
    {
        nodes.resize(size<<2|1);
    }
    void update_range(const int objL,const int objR,const int diff)
    {
        update_range(objL,objR,diff,1,1,size);
    }
    int query_point(const int obj)
    {
        return query_point(obj,1,1,size);
    }
};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> last(m+1);
    vector<pair<int,int>> ranges;
    ranges.emplace_back();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(last[a[i]]!=0)
        {
            ranges.emplace_back(last[a[i]],i-1);
        }
        last[a[i]]=i;
    }
    sort(ranges.begin()+1,ranges.end());
    SegmentTree my_tree(n);
    for(int i=1;i<ranges.size();i++)
    {
        const int l=ranges[i].first,r=ranges[i].second;
        my_tree.update_range(l,r,i);
    }
    vector<int> l(n+1);
    vector<pair<int,pair<int,int>>> actions;
    for(int i=1;i<=n;i++)
    {
        l[i]=ranges[my_tree.query_point(i)].first;
        actions.emplace_back(l[i]+1,make_pair(a[i],1));
        actions.emplace_back(i+1,make_pair(a[i],-1));
    }
    sort(actions.begin(),actions.end());
    vector<int> t(m+1);
    vector<int> cnt(m+1);
    vector<int> res(m+1);
    for(auto const i:actions)
    {
        const int lo=i.first;
        const int val=i.second.first;
        const int diff=i.second.second;
        if(diff==1)
        {
            if(cnt[val]==0)
            {
                t[val]=lo;
            }
            cnt[val]++;
        }
        if(diff==-1)
        {
            if(cnt[val]==1)
            {
                res[val]+=lo-t[val];
            }
            cnt[val]--;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<res[i]<<' ';
    }
}
