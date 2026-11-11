#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long maxl=0;
    sort(a,a+n);
    for(long long i=0;i<n;i++){
        long long ans=a[i];
        long long sum=0;
        long long k=0;
        for(long long j=0;j<n;j++){
            if(ans>=a[j]&&sum<=m){
                sum+=ans-a[j];
                k++;
            }
        }
        maxl=max(maxl,k);
    }
    cout<<maxl;
    return 0;
}
