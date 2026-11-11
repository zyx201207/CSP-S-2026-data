#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        int t[1000005]={};
        for(int j=i;j<=n;j++){
            if(t[a[j]]){
                for(int k=1;k<=m;k++){
                    t[a[k]]=0;
                }
                t[a[j]]=1;
            }else{
                t[a[j]]=1;
            }
        }for(int j=1;j<=m;j++){
            ans[j]+=t[j];
        }
    }for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
