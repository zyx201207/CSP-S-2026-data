#include<bits/stdc++.h>
using namespace std;
int n,a[500001],m,p=1;
string ans;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=i;j<=n;++j)
        {
            ans+=' ';
            ans+=char(a[j]+48);
            for (int k=1;k<ans.size()-1;++k)
            {
                if (ans[k]==ans[ans.size()-1])
                {
                    p=k;
                }
            }
        }
    }
    string ans1=ans.substr(p);
    cout<<ans1;
    return 0;
}
