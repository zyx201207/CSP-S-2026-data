#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n,m,a[N],nb,na,nc,nd,m1,m2;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1 ; i <= n ; i++){
        for(int j = n  ; j >= 1 ; j--){
            nb=a[i]&a[j];
            na=a[i-1]&a[j+1];
            nc=a[i-1]&a[j];
            nd=a[i]&a[j+1];
            m1 = max(nb,na);
            m2 = max(nc,nd);
            m = (m1,m2);
        }
    }
    cout<<m;
    return 0;
}
