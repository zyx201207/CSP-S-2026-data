#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }
    if(m==2){
        long long l,r;
        long long big=a[0]&a[1];
        for(long long i=0;i<n;i++){
            l=a[i];
            for(long long j=i+1;j<n;j++){
                r=a[j];
                if(l&r>big){
                    big=l&r;
                }
            }
        }
        cout<<big;
    }else{
        sort(a,a+n);
        long long ans=a[n-1];
        for(long long i=n-2;i>=m-1;i--){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    return 0;
}
