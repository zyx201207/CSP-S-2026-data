#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int F(int w,int ct){
    if(ct==0)return a[w];
    int t=0;
    for(int i=w+1;i<=n-ct+1;i++){
        t=max(t,(a[w] & F(i,ct-1)));
    }
    return t;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    a[0]=2e30-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<F(0,m);
    return 0;
}
