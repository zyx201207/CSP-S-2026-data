#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll sz;
    char s;
};
vector<node> v;
stack<node> st;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m=0;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        ll x;
        char s;
        cin>>x;
        cin>>s;
        v.push_back({x,s});
        m+=x;
    }
    ll now=0,it=0,tot=0;
    while(now+v[it].sz<=m/2)
    {
        st.push(v[it]);
        now+=v[it].sz;
        ++it;
    }
    if(now!=m/2)
    {
        st.push({m/2-now,v[it].s});
        v[it].sz-=m/2-now;
        now=m/2;
    }
    if(m%2==1)v[it].sz--;
    for(int i=it;i<n;++i)
    {
        ll sz=v[i].sz;
        char s=v[i].s;
        ll goal=now-sz;
        while(goal<=now-st.top().sz)
        {
            if(s!=st.top().s)tot+=st.top().sz;
            now-=st.top().sz;
            st.pop();
            if(st.empty())break;
        }
        if(goal!=now&&!st.empty())
        {
            if(s!=st.top().s)tot+=now-goal;
            st.top().sz-=now-goal;
            now=goal;
        }
    }
    cout<<tot<<endl;
    return 0;
}
//t=09:03 start
//t=09:13 RE
//t=09:30 ac 1 2 3
//t=09:32 ??? -744 -1916964926 -956379
//t=09:36 how char(115)+char(98) i am
//t=09:38 ac all