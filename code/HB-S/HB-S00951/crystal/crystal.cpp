#include <bits/stdc++.h>
using namespace std;
int m,n,ma1=0,ma2=0,s=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[n],b[n][n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            b[i][j]=a[j]-a[i];
        }
    }
    for(int j=n-1;j>=0;j--){
        for(int i=j-1;i>=0;i--){
            s+=b[i][j];
            if(s<m){
                ma1++;
            }
            if(s==m){
                ma1++;
                i=-1;
            }
            if(s>m){
                i=-1;
            }
        }
        if(ma1>ma2){
            ma2=ma1;
        }
        s=0;
        ma1=1;
    }
    cout<<ma2;
    return 0;
}
