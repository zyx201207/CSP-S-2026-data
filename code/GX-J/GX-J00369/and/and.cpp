#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool f1[200005];
int n,m,p;
int f(int n1){
    int m1,m2;
    m1=0;
    for(int i=n1;i<n;i++){
        if(f1[i+1]==1){
            i++;
        }m2=a[n1] & a[i+1];
        if(m2>m1){
            m1=m2;
            p=i+1;
        }
    }f1[p]=1;
    return m1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int c1,c2,d;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f1[i]=0;
    }for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++){
            d=j;
            c2=f(d);
            if(c2>c1){
                c1=c2;
            }
        }d=c1;
    }cout<<d;
}
