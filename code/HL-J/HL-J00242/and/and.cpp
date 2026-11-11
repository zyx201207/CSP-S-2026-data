#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,a[N];
/*void abc(int i){
    int x=a[i],p[1000000],ii;
    while(x>0){
        ii++;
        p[ii]=x%=2;
    }
    for(;ii>=1;ii--){

    }
}*/
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(&a[1],&a[n+1],cmp);
    if(m==1){
        cout<<a[1];
    }else{
        cout<<a[n/2];
    }
    return 0;
}
