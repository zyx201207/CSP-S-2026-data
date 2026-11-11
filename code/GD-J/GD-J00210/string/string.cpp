#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
using ll=long long;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<ll,char>> s1;
    for(int i=1;i<=n;i++)
    {
        ll a;
        char c;
        cin>>a>>c;
        s1.emplace_back(a,c);
    }
    vector<pair<ll,char>> s2=s1;
    reverse(s2.begin(),s2.end());
    ll last1=1,last2=1;
    map<ll,pair<char,char>> m;
    for(int i=0;i<n;i++)
    {
        m[last1].first=s1[i].second;
        last1+=s1[i].first;
        m[last2].second=s2[i].second;
        last2+=s2[i].first;
    }
    char C1='\0',C2='\0';
    ll res=0;
    ll last=1;
    for(auto const i:m)
    {
        auto const l=i.first;
        auto const c1=i.second.first;
        auto const c2=i.second.second;
        res+=(l-last)*(C1!=C2);
        if(c1!='\0')
        {
            C1=c1;
        }
        if(c2!='\0')
        {
            C2=c2;
        }
        last=l;
    }
    res+=(last1-last)*(C1!=C2);
    res>>=1;
    cout<<res;
}
