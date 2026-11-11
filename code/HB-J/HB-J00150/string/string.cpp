#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
    ll v;
    char ch;
    friend bool operator ==(node a,node b)
    {
        return a.v==b.v && a.ch==b.ch;
    }
    friend bool operator !=(node a,node b)
    {
        return !(a==b);
    }
};
struct string_l{
    vector <node> v;
    int length;
    void clever()
    {
        vector <node> t;
        for(auto a:v)
        {
            if(t.empty()) t.push_back(a);
            else if(prev(t.end())->ch==a.ch)
                prev(t.end())->v+=a.v;
            else
                t.push_back(a);
        }
        v=t;
    }
    bool check()
    {
        clever();
        vector <node> t;
        t=v;
        reverse(t.begin(),t.end());
        return t==v;
    }
    ll work()
    {
        ll len=v.size(),res=0;
        for(int i=0,j=len-1;i<j;i++,j--)
        {
            if(v[i]!=v[j])
            {
                if(v[i].ch==v[j].ch)
                    res+=abs(v[i].v-v[j].v);
                else if(v[i].v==v[j].v)
                    res+=v[i].v;
                else
                    res+=max(v[i].v,v[j].v);
            }
        }
        return res;
    }
}d;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch;
        int t;
        cin>>t>>ch;
        d.v.push_back(node{t,ch});
    }
    d.clever();
    if(d.check())
    {
        cout<<"0\n";
        return 0;
    }
    cout<<d.work()<<'\n';
    return 0;
}
