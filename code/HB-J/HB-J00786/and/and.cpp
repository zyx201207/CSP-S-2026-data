#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000005],ans,b[100000005];
int fun(int x,int y){
    if(y==0){
        return x;
    }
        ans=(x&fun(x,y-1));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        fun(a[i],n);
    }
    cout<<ans;
    return 0;
}
