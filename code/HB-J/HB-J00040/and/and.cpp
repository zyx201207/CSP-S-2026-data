#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    int x;
    if(m==2){
        x=a[n]&a[n-1];
    }
    cout << x;
    return 0;
}
