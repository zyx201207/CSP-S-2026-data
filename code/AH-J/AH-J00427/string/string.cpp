#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,char> > v;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x;
        char ch;
        cin>>x>>ch;
        if(v.size()==0)
        {
            v.push_back({x,ch});
        }
        else
        {
            if(v[v.size()-1].second==ch)
            {
                v[v.size()-1].first+=x;
            }
            else
            {
                v.push_back({x,ch});
            }
        }
    }
    if(v.size()==1)
    {
        cout<<0;
        return 0;
    }
    //for(auto x:v)
    //{
    //    cout<<x.first<<' '<<x.second<<'\n';
    //}
    bool flag=1;
    for(int i=0,j=v.size()-1;i<=j;i++,j--)
    {
        if(v[i].first==v[j].first&&v[i].second==v[j].second)
        {
            continue;
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        cout<<0;
        return 0;
    }
    long long l=0;
    long long r=v.size()-1;
    long long ans=0;
    while(l<r)
    {
        long long xl=v[l].first;
        long long xr=v[r].first;
        char cl=v[l].second;
        char cr=v[r].second;
        if(cl==cr)
        {
            long long x=min(xl,xr);
            v[l].first-=x;
            v[r].first-=x;
            if(v[l].first==0)
            {
                l++;
            }
            if(v[r].first==0)
            {
                r--;
            }
        }
        else
        {
            long long x=min(xl,xr);
            ans+=x;
            v[l].first-=x;
            v[r].first-=x;
            if(v[l].first==0)
            {
                l++;
            }
            if(v[r].first==0)
            {
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
