#include<bits/stdc++.h>
using namespace std;
int n,m;
int jz[500000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>jz[i];
    }
    for(int j=1;j<=m;j++){
        for(int i=n;i>=0;i--)
        {
            if(jz[i]==jz[i+1])
                continue;
            if(jz[i]==j)
            {
                cout<<i<<" ";
            }
        }
    }
    return 0;
}
