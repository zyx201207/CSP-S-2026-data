#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],ans[500010],s[500010];
int n,m,cnt=1;
int findb(int x){
    for(int l=1;l<=n;l++){
        if(b[l]==x){
                return 1;
        }
    }
    return 0;
}
int finds(int x){
    for(int l=1;l<=n;l++){
        if(s[l]==x){
                return l;
        }
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(findb(a[i])==0){
            b[cnt]=a[i];
            cnt++;
        }
    }
    sort(b,b+cnt);
    for(int i=1;i<=n;i++){
        for(int l=1;l<=n;l++){
            s[l]=0;
        }
        for(int j=i;j<=n;j++){
            if(finds(a[j])==0){
                s[j]=a[j];
            }
            else{
                for(int k=finds(a[j]);k<=n;k++){
                    s[k]=0;
                }
                s[j]=a[j];
            }
        }
        for(int j=1;j<cnt;j++){
            if(finds(b[j])!=0){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<cnt;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
