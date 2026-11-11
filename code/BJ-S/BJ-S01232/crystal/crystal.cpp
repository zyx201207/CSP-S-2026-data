#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],t[maxn];
int f(int i,int nlz){
    for(int j=i;j<=i+nlz;j++){
        if((i+j)%2) continue;
        return max(1+f((i+j)/2,nlz-j),1);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<f(a[n],m)<<endl;
    return 0;
}
