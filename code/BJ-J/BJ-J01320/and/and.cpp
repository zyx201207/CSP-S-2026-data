#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
const int N=2e5+5;
int n,m;
uint a[N];
uint ans=0;
namespace try_trie
{
    //T~~r~~i~~e//
    int l[N*33],r[N*33];
    int cnt[N*33];
    uint hyw[N*33];
    int tot=1;
    void inst(uint x)
    {
        int p=1;
        //cout<<p;
        for(int i=31;i>=0;i--)
        {
            int *nxt;
            if(x & (1<<i) ) nxt=&r[p];
            else nxt=&l[p];

            if(*nxt==0) *nxt=++tot;
            p=*nxt;
        }
        cnt[p]++;
        hyw[p]=~x;
    }
    void dfs_trie(int p)
    {
        if(m<=0) return;
        
        if(cnt[p])
        {
            //cout<<"found"<<hyw[p]<<endl;
            ans&=hyw[p];
            m-=cnt[p];
            if(m<=0) return;
        }
        else
        {
            if(l[p]) dfs_trie(l[p]);
            if(m<=0) return;
            if(r[p]) dfs_trie(r[p]);
            if(m<=0) return;
        }
    }
    void main()
    {
        for(int i=1;i<=n;i++) inst(~a[i]);
        ans=0;
        ans=(~ans);
        dfs_trie(1);
        cout<<ans;
    }
}
namespace try_dfs
{
    void dfs(int id,uint tmp)
    {
        if(id==n+1)
        {
            if(m==0)
            {
                ans=max(ans,tmp);
            }
            return;
        }
        if(n-id>=m)
        {
            dfs(id+1,tmp);
        }
        --m;
        dfs(id+1,tmp&a[id]);
        ++m;
    }
    void main()
    {
        ans=0;
        ans=~ans;
        uint _max=ans;
        ans=0;
        dfs(0,_max);
        cout<<ans;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)//Case 1
    {
        try_dfs::main();
    }
    else if(m==1)//Case 2
    {
        cout<<*max_element(a+1,a+n+1);
    }
    else if(n<=2000&&m==2)//Case3
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
    }
    else try_trie::main();
    return 0;
}