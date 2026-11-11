#include<bits/stdc++.h>
using namespace std;
int andt(int x,int y){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int cmp1[29]={0},cmp2[29]={0},re,sq=1;
    for(int t=28;t>=0;t--){
        cmp1[t]=x%2;
        cmp2[t]=y%2;
        x/=2;
        y/=2;
        if(cmp2[t]==1 && cmp1[t]==1) re+=sq;
        sq*=2;
    }
    return re;
}
int main(){
    int a[200005]={0};
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}
