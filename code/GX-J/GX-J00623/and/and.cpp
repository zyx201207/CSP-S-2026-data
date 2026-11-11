#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m,a[200005]={0},za=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            za=max(za,a[i]&a[j]);
        }
    }
    cout<<za;
    return 0;
}
