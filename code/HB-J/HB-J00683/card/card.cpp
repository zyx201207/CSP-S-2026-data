#include<bits/stdc++.h>
using namespace std;
int n,a[510000],m,c[310000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
        for(int k=1;k<j;k++){
        if(a[k]==a[j]){
        for(int l=k;l<j;l++)a[l]=0;
        }
        }
        }
        for(int k=1;k<=m;k++){
        bool f=1;
        for(int l=1;l<=n;l++){
        if(a[l]==k&&f==1){
            c[k]++;
            f=0;
        }
        }
        }
    }
    for(int i=1;i<=m;i++){
        if(i<m)cout<<c[i]<<" ";
        else cout<<c[i];
    }
    return 0;
}
