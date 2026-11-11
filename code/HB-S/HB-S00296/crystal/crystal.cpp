#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N];
long long m,s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        long long x=i*a[i]-s[i];
        if(x<=m){
            cout<<i;
            return 0;
        }
        else continue;
    }
}
