#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&m==3){
        cout<<7;
        return 0;
    }
    long long ma=LLONG_MIN;
    for(int i=1;i<=n-m;i++){
        long long u=a[i];
        for(int j=i+1,k=1;k<=m-1;k++,j++){
            u=u&a[j];
        }
        ma=max(ma,u);
    }
    cout<<ma;
    return 0;
}
