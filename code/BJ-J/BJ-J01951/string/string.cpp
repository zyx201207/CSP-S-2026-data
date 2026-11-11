#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct duan
{
    char zl;
    ll cd;
};
ll n,ans;
deque<duan> dq;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        duan ls;
        cin>>ls.cd>>ls.zl;
        dq.push_back(ls);
    }
    ans=0;
    while(!dq.empty())
    {
        if(dq.size()==1)
        {
            break;
        }
        if(dq.front().zl==dq.back().zl)
        {
            if(dq.front().cd==dq.back().cd)
            {
                dq.pop_front();
                dq.pop_back();
                continue;
            }
            if(dq.front().cd<dq.back().cd)
            {
                duan ls1=dq.front();
                duan ls2=dq.back();
                dq.pop_front();
                dq.pop_back();
                dq.push_back({(ls1.cd>ls2.cd?ls1.zl:ls2.zl),max(ls1.cd-ls2.cd,ls2.cd-ls1.cd)});
                continue;
            }
            if(dq.front().cd>dq.back().cd)
            {
                duan ls1=dq.front();
                duan ls2=dq.back();
                dq.pop_front();
                dq.pop_back();
                dq.push_front({(ls1.cd>ls2.cd?ls1.zl:ls2.zl),max(ls1.cd-ls2.cd,ls2.cd-ls1.cd)});
                continue;
            }
        }
        if(dq.front().zl!=dq.back().zl)
        {
            if(dq.front().cd==dq.back().cd)
            {
                ans+=dq.front().cd;
                dq.pop_front();
                dq.pop_back();
                continue;
            }
            if(dq.front().cd<dq.back().cd)
            {
                duan ls1=dq.front();
                duan ls2=dq.back();
                dq.pop_front();
                dq.pop_back();
                ans+=min(ls1.cd,ls2.cd);
                dq.push_back({(ls1.cd>ls2.cd?ls1.zl:ls2.zl),max(ls1.cd-ls2.cd,ls2.cd-ls1.cd)});
                continue;
            }
            if(dq.front().cd>dq.back().cd)
            {
                duan ls1=dq.front();
                duan ls2=dq.back();
                dq.pop_front();
                dq.pop_back();
                ans+=min(ls1.cd,ls2.cd);
                dq.push_front({(ls1.cd>ls2.cd?ls1.zl:ls2.zl),max(ls1.cd-ls2.cd,ls2.cd-ls1.cd)});
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}
