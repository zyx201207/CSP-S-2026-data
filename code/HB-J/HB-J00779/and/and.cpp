#include<bits/stdc++.h>
using namespace std;
long long n,m,w[1000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(w[j]>w[j+1]) swap(w[j],w[j+1]);
    cout<<w[m];
    return 0;
}
