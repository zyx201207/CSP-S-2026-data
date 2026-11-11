#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[10000000000];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=m;j++)
        {
            if(a[j]==a[j-2])
            {
                cout<<j;
            }
        }
    }
}

