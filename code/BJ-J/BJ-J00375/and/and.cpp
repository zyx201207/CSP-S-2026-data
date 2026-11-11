#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool vis[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    int tot=0;
    for(int k=30;k>=0;--k)
    {
        int sz=0;
        for(int i=1;i<=n;++i)
        {
            if(vis[i])continue;
            if((a[i]>>k)%2==1)++sz;
        }
        if(sz>=m)
        {
            tot+=(1<<k);
            for(int i=1;i<=n;++i)
            {
                if(vis[i])continue;
                if((a[i]>>k)%2==0)vis[i]=true;
            }
        }
    }
    cout<<tot<<endl;
    return 0;
}
//t=09:41 start thinking
//t=09:43 01Tire?? but this is j
//t=09:45 let's try it
//t=09:52 no too slow,might dp?
//t=09:56 ha? 01Tire is right? it seem like a special 01Tire
//t=09:58 no 01Tire.sort it and do the pre-sum for each wei
//t=10:02 how char(115)+char(98) i am
//        the lenth<=30,just sreach it with a set
//t=10:13 no set,arry enough
//t=10:22 start test
//t=10:41 ac 1
//t=10:44 ac all