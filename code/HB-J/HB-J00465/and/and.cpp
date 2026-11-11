#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,f=1;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=4){
            f=0;
        }
    }
    sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
    }
    else if(m==n){
        int ans=2147483647;
        for(i=0;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        int ma=-1;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                int d=a[i]&a[j];
                ma=max(ma,d);
            }
        }
        cout<<ma;
    }
    else if(f){
        cout<<a[n-m];
    }
    else{
        cout<<a[n-1];
    }
    return 0;
}
