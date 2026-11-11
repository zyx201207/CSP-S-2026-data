#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct Node
{
    long long ci;
    char c;
}qian[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>qian[i].ci>>qian[i].c;
    }
    long long ans=0;
    int l=1,r=n;
    while(l<=r)
    {
        if(qian[l].c==qian[r].c)
        {
            if(qian[l].ci>qian[r].ci)
            {
                qian[l].ci-=qian[r].ci;
                r--;
                // ans don't ++

            }
            else if(qian[l].ci<qian[r].ci)
            {
                qian[r].ci-=qian[l].ci;
                l++;
                // ans don't ++
            }
            else
            {
                l++;
                r--;
            }
        }
        else
        {
            ans+=min(qian[l].ci,qian[r].ci);
            // ans xiugai
            if(qian[l].ci>qian[r].ci)
            {
                qian[l].ci-=qian[r].ci;
                r--;

            }
            else if(qian[l].ci<qian[r].ci)
            {
                qian[r].ci-=qian[l].ci;
                l++;
                // ans don't ++
            }
            else
            {
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
