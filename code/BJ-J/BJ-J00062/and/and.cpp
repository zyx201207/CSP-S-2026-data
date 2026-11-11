#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long k,ma=0;
    for(long long i=0;i<n;i++){
        cin>>k;
        ma=max(ma,k);
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
