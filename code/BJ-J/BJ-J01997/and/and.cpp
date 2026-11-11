#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1024],Max=-1;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j) Max=max(Max,a[i]&a[j]);
            }
        }
        cout << Max;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
