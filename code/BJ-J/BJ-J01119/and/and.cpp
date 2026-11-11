#include<bits/stdc++.h>
using namespace std;
long long a[4000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cnt=0,mx=-1;
    for(int i=1;i<=n;i++){
        cnt=a[i]&a[i+1];
        if(cnt>mx) mx=cnt;
    }
    cout<<mx;
    return 0;
}
