#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1) cnt[1]++;
        if(a[i]==2) cnt[2]++;
    }
    if(a[n]==1) cnt[1]=n;
    else if(a[n]==2) cnt[2]=n;
    cout<<cnt[1]<<cnt[2];
}
