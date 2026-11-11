#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,a[10000],cnt[1000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>cnt[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>n-1;j--){
            cnt[i]+=a[i];
            if(cnt[i]==a[i]){
                cnt[i]-cnt[i-1];
                cout<<cnt[i];
            }
        }
    }
    return 0;
}
