#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200020];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(m==1){
        cout<<a[n];
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    if(m==2){
        cout<<(a[n]&a[n-1]);
    }
    if(m==n-1){
        int cnt=a[2];
        for(int i=3;i<=n;i++){
            cnt=(cnt&a[i]);
        }
    }
    return 0;
}
