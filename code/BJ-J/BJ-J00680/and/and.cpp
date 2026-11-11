#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int b[200005];
int k,lstk;
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    lstk=n;
    k=n;
    for(int j=30;j>=0;j--){
        k=0;
        for(int i=1;i<=lstk;i++){
            if(a[i]&(1<<j)){
                b[++k]=a[i];
            }
        }
        if(k>=m){
            ans|=(1<<j);
            memcpy(a,b,sizeof(int)*(k+1));
            lstk=k;
        }
    }
    cout<<ans;
    return 0;
}