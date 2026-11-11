#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    unsigned long long m;
    cin>>n>>m;
    vector<long long>a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    for(int len=n;len>1;len--){
        for(int l=1;l<=n-len+1;l++){
            unsigned long long sum=0;
            for(int i=1;i<len;i++){
                sum+=(b[l+i]*i);
                if(sum>m) break;
            }
            if(sum<=m){
                cout<<len;
                return 0;
            }
        }
    }
    cout<<1;
    return 0;
}
