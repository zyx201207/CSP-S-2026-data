#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],maxs=INT_MIN;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=n;i>=1;i--)
    {
        vector<int>v;
        for(int j=n;j>=i;j--)
        {
            v.push_back(a[j]-a[i]);
        }
        int mi=m,cnt=0;
        for(int j=0;j<v.size();j++)
        {
            if(mi+v[j]>=0)
            {
                mi+=v[j];
                cnt++;
            }
            else break;
        }
        maxs=max(maxs,cnt);
    }
    cout<<maxs<<endl;
    return 0;
}
