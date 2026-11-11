#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],b[500000];
int check(int j,int i){
    return a[j]*(j-i+1)-(b[j]-b[i-1]);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    b[0] = a[0];
    for(int i=1;i<n;i++){
        b[i]=b[i-1]+a[i];
    }
    int ma=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(check(j,i)<=m) ma=max(ma,j-i+1);
            else break;
        }
    }
    cout<<ma;
}
