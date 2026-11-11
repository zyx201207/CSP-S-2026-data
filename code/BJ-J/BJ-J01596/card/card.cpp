#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N];
int cnt[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        vector<int> v;
        for(int j=i;j<=n;j++)
        {
            for(int k=v.size()-1;k>=0;k--)
            {
                if(v[k]==a[j])
                {
                    for(int l=k,sz=v.size();l<sz;l++) v.pop_back();
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(const int&num:v)
        {
            cnt[num]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
