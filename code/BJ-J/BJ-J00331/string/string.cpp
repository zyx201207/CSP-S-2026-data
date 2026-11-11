#include<bits/stdc++.h>
using namespace std;
struct str
{
    char p;
    long long q;
};
long long n,ans;
deque<str>s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    long long x;
    char y;
    for(long long i=1;i<=n;i=i+1)
    {
        cin>>x>>y;
        s.push_back({y,x});
    }
    while(!s.empty())
    {
        if(s.size()==1)
        {
            break;
        }
        if(s.front().q==s.back().q&&s.front().p==s.back().p)
        {
            s.pop_front();
            s.pop_back();
        }
        else if(s.front().p==s.back().p)
        {
            if(s.front().q>s.back().q)
            {
                s.front().q-=s.back().q;
                s.pop_back();
            }
            else
            {
                s.back().q-=s.front().q;
                s.pop_front();
            }
        }
        else if(s.front().q==s.back().q)
        {
            ans=ans+s.front().q;
            s.pop_front();
            s.pop_back();
        }
        else
        {
            ans=ans+min(s.front().q,s.back().q);
            if(s.front().q>s.back().q)
            {
                s.front().q-=s.back().q;
                s.pop_back();
            }
            else
            {
                s.back().q-=s.front().q;
                s.pop_front();
            }
        }
    }
    cout<<ans;
    return 0;
}