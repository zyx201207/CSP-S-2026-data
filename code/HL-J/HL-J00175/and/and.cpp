#include<bits/stdc++.h>
using namespace std;
long long a[1000000],sum=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        if(a[i]&a[i+1]>sum)sum=a[i]&a[i+1];
    }cout<<sum;
    return 0;
}
