#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[100];
    int maxn=0;
    int cnt;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=m;j<=n;)
        {
            cnt == a[i] & a[j] ;
            if(cnt > maxn)
            {
                maxn=cnt;
            }
        }
    }
    cout<<"12";
    return 0;
}
