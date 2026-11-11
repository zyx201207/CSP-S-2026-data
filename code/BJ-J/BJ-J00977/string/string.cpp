#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node
{
    int a;
    char c;
};
int ans=0;
deque<node> dq;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;char c;
        cin>>a>>c;
        if(i>1)
        {
            node x=dq.back();
            if(c==x.c)
            {
                dq.pop_back();
                dq.push_back({a+x.a,c});
                continue;
            }
        }
        dq.push_back({a,c});
    }
    while(dq.size()>1)
    {
        node x=dq.front(),y=dq.back();
        dq.pop_front();dq.pop_back();
        //cout<<x.a<<' '<<x.c<<' '<<y.a<<' '<<y.c<<"\n";
        if(x.c==y.c)
        {
            if(x.a>y.a)
            {
                dq.push_front({x.a-y.a,x.c});
            }
            else if(x.a<y.a)
            {
                dq.push_back({y.a-x.a,y.c});
            }
        }
        else
        {
            if(x.a>y.a)
            {
                dq.push_front({x.a-y.a,x.c});
                ans+=y.a;
            }
            else if(x.a<y.a)
            {
                dq.push_back({y.a-x.a,y.c});
                ans+=x.a;
            }
            else
            {
                ans+=x.a;
            }
        }
    }
    cout<<ans;
    return 0;
}
