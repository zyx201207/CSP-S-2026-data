#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[500005]={0},b[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=abs(a[i+1]-a[i]);
    }
    sort(b+1,b+n);
    a[1]=b[1];
    for(int i=2;i<n;i++){
        a[i]=a[i-1]+b[i];
    }
    sort(a+1,a+n);
    long long i=1;
    while(m>=a[i]){
        m-=a[i];
        i++;
    }
    cout<<min(i,n);
    return 0;
}
