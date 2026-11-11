#include<bits/stdc++.h>
using namespace std;
int w[100000000];
int R[100000000][100000000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int k;
    cin>>c>>n>>m>>d>>q;
    for(int p=0;i<m;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n-2;i++)
    {
        cin>>k;
        R[i][0]={k};
        for(int t=1;t<=2*k;i++)
        {
            cin>>R[i][t];
        }
    }
    return 0;
}
