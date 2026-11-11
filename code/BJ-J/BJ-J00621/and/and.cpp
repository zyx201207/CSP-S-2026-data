#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long man=0,i=0;
bool cmp(int a,int b){
    return a>b;
}
bool wanq(int a){
    while(a){
        if(a!=1 && a%2==1) return false;
        a/=2;
    }
    return true;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    if(m==2){
        while(wanq(a[m])){
           m++;
        }
        m++;
    }
    cout<<a[m];
    return 0;
}
