#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long q[500005],cnt[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cnt[i]=n;
    }

    for(int i=1;i<=n;i++){
        cin>>q[i];
        if(m==1){
            cout<<n;
            return 0;
        }
        for(int j=1;j<i;j++){
            if(q[i]==q[j]){
                for(int k=j;k<i;k++){
                    cnt[q[k]]--;
                }
            }
        }
    }
    bool ans=true;
    if(n==m){

        for(int i=2;i<=n;i++){
            if(q[i-1]+1!=q[i]) ans=false;
        }

    }
    int c=m;
    if(ans){
        for(int i=1;i<=m;i++){
            cout<<c<<" ";
            c--;
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }

    return 0;
}

