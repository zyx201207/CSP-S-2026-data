#include <bits/stdc++.h>
using namespace std;
long long a[500000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=1;
    long long t=n;
    while(t>=0){
        long long k=m;
        long long rule=a[t];
        long long k1=0;
        for(long long i=t-1;i>=0;i--){
            long long temp=2;
            if(k<=0){
                break;
            }
            if(rule-a[i]<=k){
                k=k-rule+a[i];
                temp++;
            }
            if(temp>=ans){
                ans=temp;
            }
        }

        t--;
    }
    cout<<ans<<endl;
    return 0;
}
