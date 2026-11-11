#include <iostream>
#include <vector>
#include <cstdio>
std::vector<bool> vis;
int c,t,n,d;
std::vector<int> a;
std::vector<int > ans;
int dfs(int x,int dep)
{
    if(x >= n)
    {
        ans.push_back(dep);
    }
    for(int i=1;i<=d and n-i-x>0;i++)
    {
        (dfs(x+i,dep+1));
    }
    return dep;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate,out","w",stdout);

    int c;
    std::cin>>c>>t;
    while(t--)
    {
        a.clear();
        ans.clear();
        std::cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            int x;
            std::cin>>x;
            a.push_back(x);
        }

    dfs(0,0);
    int anss = 0;
    int len = ans.size();
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(ans[i] == ans[j])
            {
                anss++;
            }
        }
    }

    std::cout<<anss<<std::endl;
    }
}
