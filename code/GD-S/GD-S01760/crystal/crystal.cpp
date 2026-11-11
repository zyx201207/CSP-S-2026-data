#include<bits/stdc++.h>
using namespace std;
long long n,m,d,a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    d=a[n]-a[n-1];
    for(int i=n;i>=1;i--){
        long long sum=0;
        for(int j=1;j<i;j++){
            sum+=(i-j)*d;
        }
        if(sum<=m){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
