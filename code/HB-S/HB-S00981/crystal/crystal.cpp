#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500001],i,o;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    o=m/(abs(a[2]-a[1]))*2;
    int p=sqrt(o);
    if(p*(p+1)<=o)cout<<p+1;
    else cout<<p;
    return 0;
}
