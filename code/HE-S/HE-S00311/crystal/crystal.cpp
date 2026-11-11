#include<bits/stdc++.h>
using namespace std;
int n,m,an[500005];
vector<pair<int,int>>ansss;
struct node
{
    int a,b,s;
    int operator>(const node& other)const
    {
        return s<other.s;
    }
};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    priority_queue<int,vector<int>,greater<int>>pqs;
    vector<node>v;
    for(int i=1;i<=n;i++)
    {
        cin >> an[i];
        pqs.push(an[i]);
    }
    for(int i=1;i<n;i++)
    {
        int a=pqs.top();
        pqs.pop();
        int b=pqs.top();
        pqs.pop();
        v.push_back({a,b,b-a});
        pqs.push(b);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int tage=0,type=m;
        while(v.size()>tage+1+i&&type>v[tage+i].s)
        { 
			tage++;
            type-=v[tage+i-1].s;
        }
        ans=max(ans,tage);
    }
    cout << ans + 1;

    return 0;
}
