#include <bits/stdc++.h>
using namespace std;
const long long N=500000+9;
long long n,m;
long long a[N];
long long b[N];
long long maxx=-10;
long long qp(long long n,long long s){
    if(s==1){
        for(int i=1;i<=n;i++){
        if(b[i]==0)
        return a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
        b[i]=1;
        if(m==s){
        maxx=max(maxx,a[i]&qp(n,s-1));
        }else{
            return a[i]&qp(n,s-1);
        }
        b[i]=0;
        }
    }
    if(s==m)
    return maxx;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<qp(n,m);
    return 0;
}
