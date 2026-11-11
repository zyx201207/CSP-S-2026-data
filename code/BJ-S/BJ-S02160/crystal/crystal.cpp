#include<bits/stdc++.h>
using namespace std;
long long m,h=0,mim=0,g=0;
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int NN=n+10;
    int a[NN];
    for(int i=0;i<n;i++){
    cin>>a[i];
    }
    sort(a,a+n);
    int b[NN];
    for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
    b[j]=a[i]-a[j];
    }
    sort(b,b+i);
    for(int j=0;j<i;j++){
    if(b[j]>m){break;}
    else{
    m-=b[j];
    g++;
    }
    }
    mim=max(mim,g);
    }
    cout<<mim;
    return 0;
}
