#include <bits/stdc++.h>
using namespace std;
long long f[100000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max_=0,cnt=0;
    cin>>n>>m;
    if(m)
    {
        for(int i=0;i<n;i++)
        {
            cin>>cnt;
            if(cnt>=max_) max_=cnt;
        }
    }
    if(m==n)
    {
        int cnt1;
        for(int i=0;i<n;i++)
        {
            cin>>cnt;
            if(i==0) cnt1=cnt;
            else
            {
                cnt1=(cnt1&cnt);
            }
        }
        cout<<cnt1;
    }
    return 0;
}
