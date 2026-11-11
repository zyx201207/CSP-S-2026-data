#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],c,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ans=a[n-1];
    for(int i=n-1;i>=n-m;i--){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}

//5 3
//31 3 1 15 7
//4 2
//3 15 12 12
