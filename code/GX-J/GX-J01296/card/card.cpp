#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1],b[n+1],cnt_tt[m+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[j]=a[j];
        }
        int cnt[m+1]={0},idx=1,last_idx[m+1]={0};
        for(int j=i;j<=n;j++){
            if(last_idx[b[j]]>0){
                for(int k=last_idx[b[j]];k<j;k++){
                    b[k]=0;
                }
            last_idx[b[j]]=j;
            }
        }
        for(int j=i;j<=n;j++){
            cnt[b[j]]=1;
        }
        for(int j=1;j<=m;j++){
            cnt_tt[j]+=cnt[b[j]];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt_tt[i]<<" ";
    }
    return 0;
}
