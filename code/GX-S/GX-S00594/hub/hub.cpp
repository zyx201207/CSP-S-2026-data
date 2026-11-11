#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int b[100000000][100000000];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    int n,k;
    cin>>c>>t;
    cin>>n>>k;
    for(int i=1;i<=n-1;t++)
    {
        cin>>b[i];
        for(int p=0;p<2;p++)
        {
            cin>>b[i][p];
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<a[i];
    }
    return 0;
}
