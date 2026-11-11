#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[100001],c;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        if(a[i]<a[i+1]){
            sort(a[i],a[i+1]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(a[i+j]==a[j]){
                c=a[i];
            }
        }
    }
    cout<<c;
    return 0;
}
