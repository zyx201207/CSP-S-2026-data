#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct node{
    long long x;
    char y;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int l=1,r=n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1].y!=a[2].y){
            if(a[1].x>a[2].x) cout<<a[2].x;
            else cout<<a[1].x
        }
        else cout<<0;
        return 0;
    }
    while(l<r){
        if(a[l].x>a[r].x){
            if(a[l].y!=a[r].y) ans+=a[r].x;
            a[l].x-=a[r].x;
            r--;}
        else{
            if(a[l].y!=a[r].y) ans+=a[l].x;
            a[r].x-=a[l].x;
            l++;}
    }
    cout<<ans;
    return 0;
}