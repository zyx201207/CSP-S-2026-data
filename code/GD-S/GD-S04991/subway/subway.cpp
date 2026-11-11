#include <bits/stdc++.h>

using namespace std;

int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010],x,y;
vector<int> line[500010];
bool vis[500010];

struct SS
{
    int to, time;
};

struct Heap
{
    vector<SS> data;
    inline void push(const SS& ss)
    {
        data.push_back(ss);
        int curr=data.size()-1;
        while(curr>1&&data[curr-1].time>data[curr].time)
            swap(data[curr-1], data[curr]);
    }
    inline SS pop()
    {
        SS ss=data[data.size()-1];
        data.pop_back();
        return ss;
    }
} sstack;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
//    printf("%d,%d,%d,%d,%d\n",c,n,m,d,q);
    for(int i=1;i<=m;i++) scanf("%d", &w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%d%d", &a[i][j], &t[i][j]);
            line[a[i][j]].push_back(i);
        }
    }

    for(int i=1;i<=q;i++)
    {
        scanf("%d%d", &x, &y);
        int cnt=m;
        memset(vis, 0, sizeof(vis));
        sstack.data.clear();
        SS ss;
        ss.to=x;
        ss.time=w[x];
        sstack.push(ss);
//        printf("aaa\n");
        while(!sstack.data.empty())
        {
//            printf("bbb\n");
            ss=sstack.pop();
            vis[ss.to]=1;
            if(ss.to==y)
            {
                printf("%d\n", ss.time+w[y]);
                break;
            }
            for(int l: line[ss.to])
            {
//                printf("ccc\n");
                for(int j=1;j<=k[l];j++)
                {
//                    printf("ddd\n");
                    SS ss2;
                    ss2.to=a[l][j];
                    ss2.time=ss.time+=t[l][ss.to]+t[l][j];
//                    printf("<%d,%d>\n", ss2.to, ss2.time);
                    sstack.push(ss2);
                }
            }
        }
    }

    return 0;
}