#include<bits/stdc++.h>
using namespace std;
int cnt[333333],a[555555];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int id=i-1;
        while(id<n){
            for(int j=n;j>id;j--){
                if(a[j]==a[id+1]){
                    id=j;
                }
            }
            cnt[a[id]]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}


