#include<bits/stdc++.h>
using namespace std;
int a[20000],n,m,l=0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>l) l=a[i];
    }
    if(m==1) cout<<l;
    if(m==2){
        l=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]&a[j]>=l) l=a[i]&a[j];
            }
        }
        cout<<l;
     }
    return 0;
}