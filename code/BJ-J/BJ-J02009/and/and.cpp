#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,t;
int a[N];
int vv(int a,int b){
    return a & b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>> n>> t;
    for(int i=1;i<=n;i++){
        cin>> a[i];
    }
    sort(a+1,a+n+1);
    int sum=a[n]
    for(int i=n-1;i>n-t;i--){
        int x=a[i];
        sum=vv(sum,x);
    }
    cout<< sum;
    return 0;
}
