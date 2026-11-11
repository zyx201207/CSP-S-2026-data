#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[n],b[n-1],maxn=-1,sum=0,x=0;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        b[i]=a[i+1]-a[i];
    }
    for(int i=0;i<n-1;i++){
            x=0;
        for(int j=i,sum=0;sum<m&&j<n-1;j++,x++){
            sum+=b[j];
        }
        maxn=max(maxn,x);
    }
    cout<<maxn;
    return 0;
}
