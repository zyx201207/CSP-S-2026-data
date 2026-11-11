#include<bits/stdc++.h>
using namespace std;
const int a=1000000;
int ans[a]={0},b[a];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long shu;
        cin>>shu;
        ans[shu]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
