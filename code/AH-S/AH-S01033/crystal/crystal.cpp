#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main(){
    int n,m;
    cin>>n>>m;
    for(int p=1;p<=n;p++){
        cin>>a[p];
    }
    for(int p=1;p<=n;p++){
        for(int p=n-1;p>=0;p--){
            for(int q=1;q<=n;q++){
                if(a[p]>a[p+1]){
                    swap(a[p],a[p+1]);
                }
            }
        }
    }
    for(int p=1;p<=n;p++){
        b[p]=a[p+1]-a[p];
    }
    int ans=0;
    for(int p=1;p<=n-1;p++){
        if(b[p]<=m-1&&b[p]>0){
            ans++;
        }
    }
    cout<<ans-1;
    return 0;
}
