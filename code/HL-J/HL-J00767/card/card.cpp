#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],top,t[500005];
vector<long long>vec[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>0;i--)
    {
        if(t[a[i]])
        {
            while(s[top]!=a[i])
            {
                t[s[top]]--;
                vec[s[top]].push_back(i);
                top--;
            }
        }
        else
        {
            s[++top]=a[i];
            t[s[top]]++;
            vec[s[top]].push_back(i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        long long ans=0;
        for(int j=1;j<vec[i].size();j+=2)
        {
            ans+=vec[i][j-1]-vec[i][j];
        }
        if(vec[i].size()%2)
        {
            ans+=vec[i][vec[i].size()-1];
        }
        cout<<ans<<' ';
    }




    return 0;
}
