#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010]={},max_=-1,t=1;
int dy(){
    int b=a[0];
    for(int i=1;i<n;i++){
        b&=a[i];
    }
    return b;
}
void bl(int jz,int shu,int id){
    if(jz==m){
        max_=max(max_,shu);
        return;
    }
    if(id==n){
        return;
    }
    if(jz==0){
        bl(jz+1,a[id],id+1);
    }
    else{
        bl(jz+1,shu&a[id],id+1);
    }
    bl(jz,shu,id+1);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }
    else if(m==n){
        cout<<dy();
    }
    else{
        bl(0,0,0);
        cout<<max_;
    }
    return 0;
}

