#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,lis[1000001];
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>lis[i];
    for(int i=m;i>=1;i--)cout<<i<<" ";

    return 0;
}
