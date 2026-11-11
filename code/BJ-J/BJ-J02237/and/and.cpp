#include<bits/stdc++.h>
using namespace std;
int m,n,ma,ans;
int a[200007];

int main(){
    cin>>n>>m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=er(a[i]);
    }sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
        return 0;
    }if(m==n){
        int b=a[0];
        for(int i=0;i<n;i++){
            b=b&a[i];
        }cout<<b;
        return 0;
    }
    
    return 0;
}