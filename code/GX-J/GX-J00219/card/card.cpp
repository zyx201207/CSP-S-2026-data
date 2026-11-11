#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pref[500005],cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            pref[a[j]]++;
            if(pref[a[j]]==2) pref[a[j]]==0;
        }
        for(int l=1;l<=m;l++){
            if(pref[a[l]]!=0) cnt[l]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
