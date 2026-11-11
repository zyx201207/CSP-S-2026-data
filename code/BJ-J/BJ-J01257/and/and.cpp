#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1048580],b[1048580],ucg[1048580][10];
int smaller(int a,int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

        }

    int ans;
    for(int i=1;i<=n;i++){
        ans=smaller(a[i],a[1]);
    }
    cout<<ans;
    return 0;
}
