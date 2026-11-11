#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],cnt,ans[200005];
void check(int w){
    bool q=0;
    int id;
    for(int k=1;k<=cnt;k++){
        if(b[k]==w){
            q=1;
            id=k;
        }
    }
    if(q==1){
        for(int y=id;y<=cnt;y++) b[y]=0;
        cnt=id-1;
    }
}
void ans1(){
    for(int j=1;j<=m;j++){
        for(int k=1;k<=cnt;k++){
            if(b[k]==j) ans[j]++;
            break;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            check(a[j]);
            b[++cnt]=a[j];
        }
        ans1();
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
