#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(double x,double y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
    }
    if(m==2){
        cout<<a[2];
    }
    if(m==n){
        cout<<0;
    }
    return 0;
}