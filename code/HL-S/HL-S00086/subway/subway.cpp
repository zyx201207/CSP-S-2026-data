#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int k[n];
    int a[n][10000],t[n][10000];
    for(int i=0;i<n;i++)
    {

        cin>>k[i];
        for(int j=0;j<2*k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    int beginplace[q],finishplace[q];
    for(int i=0;i<q;i++)
    {
        cin>>beginplace[i]>>finishplace[i];
    }
}
