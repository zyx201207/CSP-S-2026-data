
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define LL long long int
long long int x[2000005];
bool cmp(LL a,LL b)
{
    return a>b;
}
long long int res=0;
struct node{
    long long int x;
    long long int level;
};
long long int ml[2000005];
long long int step[2000005];
std::deque<node> q;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long int c,t;
    std::cin>>c>>t;
    while(t--)
    {
        long long int n,d;
        std::cin>>n>>d;
        for(int i=1;i<=n;i++)
            std::cin>>x[i];
        for(int i=1;i<=n;i++)
        {
            node a={i,0};
            memset(ml,0x3f,sizeof(ml));
            memset(step,0,sizeof(step));
            ml[i]=0;
            q.push_back(a);
            while(!q.empty())
            {
                node p=q.front();
                //std::cout<<p.x<<' '<<p.level<<'\n';
                q.pop_front();
                if(p.level>ml[p.x])
                    continue;
                else
                    step[p.x]++;
                for(int i=p.x+1;i<=n;i++)
                {
                    if(x[i]-x[p.x]<=d&&p.level+1<=ml[i]){
                        ml[i]=p.level+1;
                        q.push_back({i,p.level+1});
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(step[i]==2)
                    res++;
                //std::cout<<step[i]<<' ';
            }
            //std::cout<<'\n';
        }
        std::cout<<res<<'\n';
        res=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
