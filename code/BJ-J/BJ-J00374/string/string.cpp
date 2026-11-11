#include <bits/stdc++.h>
using namespace std;
int n;
int l;
int r;
long long ans;
vector<pair<int,char> > v(200010);
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    l=1;
    r=n;
    while (l<=r)
    {
        if (v[l].second!=v[r].second)
        {
            if (v[l].first<v[r].first)
            {
                ans+=v[l].first;
                v[r].first-=v[l].first;
                l++;
            }
            else if (v[l].first==v[r].first)
            {
                ans+=v[l].first;
                l++;
                r--;
            }
            else
            {
                ans+=v[r].first;
                v[l].first-=v[r].first;
                r--;
            }
        }
        else
        {
            if (v[l].first<v[r].first)
            {
                v[r].first-=v[l].first;
                l++;
            }
            else if (v[l].first==v[r].first)
            {
                l++;
                r--;
            }
            else
            {
                v[l].first-=v[r].first;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
