#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1)
    {
        int max=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x>max)
                max=x;
        }
        cout<<max;
    }
    return 0;
}
