#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m[100],n,a;
    int ans;
    cin>>n;
    for(int i=0;i<=n;++i)
    {
        if(m[i]==0)
        {
            cout<<m[i]<<endl;
            m[i++];
            if(m[0]!=0)
            {
                cout<<ans;
            }
        }
    }
    return 0;
}
