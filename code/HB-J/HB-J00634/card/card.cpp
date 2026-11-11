#include<bits/stdc++.h>
using namespace std;
int n,m,a[1111111];
int main(){

    cin>>n>>m;
    int b[m+5],c[n+5];
    for(int i = 1;i<=m;i++){
        b[i] = c[i] = 0;
    }
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
   // cout<<1;

    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            if(b[a[j] ]== 1) {
                for(int z = 1;z<=j;z++){
                    b[a[z] ]= 0;
                }
                b[a[j]] = 1;
            }else b[a[j]] = 1;
        }
        int ans = 0;
        for(int j = 1;j<=m;j++) {
            if(b[j] == 1) c[j]++;
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<c[i]<<" ";
    }
  //  cout<<1;
    return 0;
}
