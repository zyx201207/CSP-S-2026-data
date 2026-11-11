#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005],cnt[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){
            cnt[a[j]]++;
            if(cnt[a[j]]==2){

                for(int k=1;k<m;k++){
                    if(cnt[k]!=0){
                        cnt[k]--;
                    }
                }
            }
        }
        for(int k=1;k<=m;k++){
            if(cnt[k]!=0) ans[k]++;
            cnt[k]=0;
        }


    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


