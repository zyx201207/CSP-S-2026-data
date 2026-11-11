#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];int ans[100005],v[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {

        string s="";
        for(int j=i; j<=n; j++)
        {

            for(int k=0; k<s.size(); i++)
            {
                if(a[j]+'0'==s[k])
                {
                    s.erase(k,s.size()-k);
                    break;
                }
            }
            s+=char(a[j]+'0');
        }
        for(int j=0; j<s.size(); j++)
        {
            ans[s[j]-'0']++;
        }
    }

    for(int i=1; i<=m; i++)
    {
        cout<<ans[i]<<" ";
    }



    return 0;
}
