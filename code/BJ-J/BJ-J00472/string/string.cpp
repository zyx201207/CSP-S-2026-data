#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(NULL),cout.tie(NULL);
    cin>>n;
    vector<long long>m(n+1);
    vector<char>c(n+1);
    for(long long i=1;i<=n;i++){
        cin>>m[i]>>c[i];
    }
    long long l=0,r=n-1,ll=m[l],lr=m[r];
    while(l<r){
        long long k=min(ll,lr);
        if(c[l]!=c[r]){
            ans+=k;
            ll-=k,lr-=k;
        }
        if(ll==0){
            l++;
            ll=m[l];
        }
        if(lr==0){
            lr--;
            lr=m[r];
        }
    }
    cout<<ans;
    return 0;
}
