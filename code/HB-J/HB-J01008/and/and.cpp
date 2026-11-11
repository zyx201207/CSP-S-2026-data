#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200004],ans=0x7fffffff;
    int ran=31;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());




    int v=1,last=(int)log2(a[1]);
    for(int i=2;i<=m;i++){
        if((int)log2(a[i])!=last)v=1;
        else v++;
        last=(int)log2(a[i]);
        if(v>=m){
            ran=last;
        }
    }
    if(v<m)ran=(int)log2(a[m]);





    if(ran<30){
    for(int i=1;i<=n;i++){
        a[i]%=(int)pow(2,ran+1);
    }}
    sort(a+1,a+1+n,greater<int>());


    for(int i=1;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
