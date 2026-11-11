#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=n;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>a[j]){
                b[i]--;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]==n+1-m){
            cout<<a[i];
            return 0;
        }
    }
    return 0;
}
