#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005];
long long mx,cur;
long long l,r;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    l=r=1;
    while(l<=r&&r<n){
        //cout<<l<<' '<<r<<'\n';
        while(a[r]*(r-l+1)-(s[r]-s[l-1])<=m){
            //cout<<l<<' '<<r<<' '<<a[r]*(r-l+1)<<' '<<s[r]-s[l-1]<<' '<<a[r]*(r-l+1)-(s[r]-s[l-1])<<'\n';
            mx=max(mx,r-l+1);
            r++;
            if(r>=n){
                break;
            }
        }
        while(a[r]*(r-l+1)-(s[r]-s[l-1])>m){
            //cout<<l<<' '<<r<<' '<<a[r]*(r-l+1)<<' '<<s[r]-s[l-1]<<' '<<a[r]*(r-l+1)-(s[r]-s[l-1])<<'\n';
            l++;
        }
    }
    cout<<mx<<'\n';
    return 0;
}
//g++ -O2 -std=c++14 ~/AH-S00055/crystal/crystal.cpp -o ~/1