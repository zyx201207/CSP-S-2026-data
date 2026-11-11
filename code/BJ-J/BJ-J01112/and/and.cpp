#include<bits/stdc++.h>;
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a,x=-1,v=-1;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a;
        x=max(a,x);
        if(v=-1) v=a;
        else v=v&a;
    }
    if(n==m) cout<<v;
    else cout<<x;
    return 0;
}