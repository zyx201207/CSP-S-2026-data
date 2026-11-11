#include <bits/stdc++.h>
using namespace std;
int a[10110];
int n;
int m;
int main(){
    cin>>n;
    cin>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    int me=0;
    for(int j=1j<=m;j++){
        for(int i=0;i<=m;i++){
            if(a[j]<a[i+1]){
            }if(a[j]+=a[i+1]){
            me+=a[j+1]-a[i];
            ans+2;
            }if(a[j]=a[i+1]){
            ans+2;
            }if(me>=m){
                cout<<ans;
            }
    }
}
    return 0;
}