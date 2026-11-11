#include<bits/stdc++.h>
using namespace std;
long long n,m,c;
long long a[1000001];
long long b[1000001];
long long cmp(long long f,long long e){
    return f<e;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(long long i=0;i<n;i++){
        b[i]=(a[i]-a[i-1])*i+b[i-1];
    }
    for(long long i=0;i<n;i++){
        if(m>=b[i]){
            c=i;
        }
    }c++;
    cout<<c<<endl;

    return 0;
}