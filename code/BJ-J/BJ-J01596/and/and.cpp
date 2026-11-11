#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,LOG=31;
int n,m;
vector<int> v,v1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=LOG;i>=0;i--)
    {
        int cnt=0;
        v1.clear();
        for(const int&num:v)
        {
            if(num&(1<<i)) cnt++,v1.push_back(num);
        }
        if(cnt>=m)
        {
            v=v1;
        }
    }
    int ans=v[0];
    for(int i=1;i<v.size();i++)
    {
        ans&=v[i];
    }
    cout<<ans;
    return 0;
}
