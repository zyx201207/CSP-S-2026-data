#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int cnt[300005];
int q[300005];
int lst[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int l=1,r=0;
        for(int j=1;j<=m;j++) lst[j]=0;
        for(int j=i;j<=n;j++){
            if(lst[a[j]]){
                int nxt=lst[a[j]]-1;
                for(int k=lst[a[j]];k<=r;k++) lst[q[k]]=0;
                r=nxt;
            }
            q[++r]=a[j];
            lst[a[j]]=r;
        }
         for(int j=l;j<=r;j++) cnt[q[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
