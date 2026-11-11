#include <bits/stdc++.h>
using namespace std;
int n,m,a[15],l1,tabel[15],l2,ans[10];
bool findx(int x){
    for(int i=1;i<=l2;i++){
        if(tabel[i]==x) return true;
    }
    return false;
}
int findy(int x){
    for(int i=1;i<=l2;i++){
        if(tabel[i]==x) return i;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int a1[15];
        for(int j=i;j<=n;j++) a1[l1]=a[j],l1++;
        for(int k=1;k<=l1;k++){
            if(l2==0){
                tabel[1]=a1[k];
                continue;
            }
            if(findx(a1[k])){
                int z=findy(a1[k]);
                for(int p=z;p<=l2;p++) tabel[p]=0;
            }
            else{
                tabel[l2+1]=a1[k],l2++;
                continue;
            }
        }
        for(int j=1;j<=l2;j++){
            ans[tabel[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
