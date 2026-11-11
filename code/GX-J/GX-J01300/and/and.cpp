#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a,b;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n/m>1){
        for(long long i=1;i<=n;i+=3){
            b[i]=a[i]&a[i+1]&a[i+2];
        }
    }
    max(b[1],b[n]);
    for(long long i=0;i<=n;i++){
    cout<<b[i]<<endl;
    }
}
