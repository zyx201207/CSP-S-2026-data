#include <bits/stdc++.h>
using namespace std;
int n,m,synn,wxnn;
int a[200005],ans[200005];
int main()
{
    freopen("travel.in","u","stdin");
    freopen("travel.out","w","stdout");
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        synn=0;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i] & a[j] > ans[j-1])
            {
                synn++;
                ans[j]=a[i]&a[j];
            }
            if(synn>m)
                break;
        }
    }
    for(int i=1;i<=n;i++)
        if(ans[i]>wxnn)
            wxnn=ans[i];
    cout << wxnn;
    return 0;
}
