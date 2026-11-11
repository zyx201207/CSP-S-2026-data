#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int c, n, m, d, q;
const int inf=100000;
vector<int> w;/*n个地铁站地面到站厅时间*/
vector<int> k;/*n个地铁线路经过k个地铁站*/
vector<int> result;/*结果*/
vector<vector<int>> a;/*i个地铁线路的地铁站*/
vector<vector<int>> t;/*i个地铁线路j地铁站时间*/
vector<vector<int>> waymap;
vector<vector<int>> plan;/*计划*/
bool finder(vector<int> in,int n2)
{
    for (int i=0;i<in.size()-1;i++)
    {
        if (in[i]==n2) return 1;
    }
    return 0;
}
bool finder2(vector<int> in,int n2)
{
    for (int i=0;i<in.size()-1;i++)
    {
        if (in[i]==n2) return i;
    }
    return 0;
}
int findaddr(int in,int out,int value,int n2)
{
    if (n2==n) return inf;
    vector<int> temp=waymap[in];
    if (finder(temp,out))
    {
        for (int tmp2=0;tmp2<n;tmp2++)
        {
            if (finder(a[tmp2],out))
            {
                result.push_back(value+t[tmp2][finder2(t[tmp2],out)]);
                for (int ti=0;ti<k[tmp2];ti++)
                {
                    findaddr(t[tmp2][ti],out,value+t[tmp2][finder2(t[tmp2],out)],n2++);
                }
            }
            else
            {
                for (int ti=0;ti<k[tmp2];ti++)
                {
                    findaddr(t[tmp2][ti],out,value+t[tmp2][finder2(t[tmp2],out)],n2++);
                }
            }
        }
    }

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c>>n>>m>>d>>q;
    a.resize(n,vector<int>());
    t.resize(n,vector<int>());
    waymap.resize(m,vector<int>());
    plan.resize(q,vector<int>(2,0));
    for (int i=0;i<m;i++)
    {
        int wi;
        cin>>wi;
        w.push_back(wi);
    }
    for (int i=0;i<n;i++)
    {
        int ki;
        cin>>ki;
        k.push_back(ki);
        for (int j=0;j<ki;j++)
        {
            int aij,tij;
            cin>>aij>>tij;
            a[i].push_back(aij);
            t[i].push_back(tij);
        }
    }
    for (int i=0;i<q;i++)cin>>plan[i][0]>>plan[i][1];
    for (int i=0;i<m;i++)
    {
        for (int tmp1=0;tmp1<n;tmp1++)
        {
            if(finder(a[tmp1],i))
            {
                for(int it=0;i<a[tmp1].size();it++)
                {
                    if (a[tmp1][it]==i) continue;
                    waymap[i].push_back(a[tmp1][it]);
                }
            }
        }
    }
    for (int i=0;i<q;i++)
    {
        findaddr(plan[i][0],plan[i][1],0,0);
        sort(result.begin(),result.end());
        cout<<result[0]<<"\n";
        result.resize(0);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
