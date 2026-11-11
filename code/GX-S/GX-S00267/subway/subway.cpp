#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
int c,n,m,d,q;
std::vector<int> w,k;
std::vector<int> x,y;
std::vector<std::vector<int>> a,t;

std::vector<bool> vis;

void clear_vis()
{
    vis.clear();
    for(int i=0;i<m;i++)
    {
        vis.push_back(false);
    }
}

bool have(std::vector<int> erpo, int p)
{
    return (std::find(erpo.begin(),erpo.end(),p)-erpo.begin() != erpo.size() or p == erpo.back());
}

int f(int from_ni,int now_ai,int end_ai,int now_ans)
{
    if(now_ai == end_ai) {return now_ans+w[end_ai];}
    int ans = 1e9;
    std::vector<int> can_go_ni;
    for(int i=0;i<n;i++)
    {
        if(have[i],now_ai) can_go_ni.push_back(i);
    }
    for(int new_ni:can_go_ni)
    {
        for(int i = 0 ;i < a[new_ni].size();i++)
        {
            int lastans = ans;
            int new_ai = a[new_ni][i];
            if(vis[new_ai]) continue;
            vis[new_ai] = true;
            ans = std::min(ans,f(new_ni,new_ai,end_ai,now_ans+t[new_ni][i]+t[from_ni][std::find(a[from_ni].begin(),a[from_ni].end(),now_ai)-a[from_ni].begin()]));
            vis[new_ai] = false;
        }
    }
    return ans;
}
int main()
{
    freopen("subway.in","r",stdin);
    //
    freopen("subway.out","w",stdout);
    std::cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        int x;
        std::cin>>x;
        w.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x1;
        std::cin>>x1;
        k.push_back(x1);
        std::vector<int > aa,tt;
        for(int j=0;j<x1;j++)
        {
            int x2,x3;
            std::cin>>x2>>x3;
            aa.push_back(x2);
            tt.push_back(x3);
        }
        a.push_back(aa);
        t.push_back(tt);
    }
    for(int i=0;i<q;i++)
    {
        int x1,x2;
        std::cin>>x1>>x2;
        x.push_back(x1);
        y.push_back(x2);
    }

    for(int i=0;i<q;i++)
    {
        clear_vis();
        std::vector<int> can_go_ni;
        for(int j=0;j<n;j++)
        {
            if(have[j],x[j]) can_go_ni.push_back(i);
        }
        int asd = 1e9;
        for(int j:can_go_ni)
        {
            asd = std::min(asd,f(j,x[j],y[j],w[x[j]]));
        }
        std::cout<<asd<<std::endl;
    }
}
