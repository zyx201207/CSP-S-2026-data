#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[600000];
int b[600000];
int s=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
        }
    if(b[n]<=m){
        cout<<n;
        return 0;
    }
    else for(int i=n;i>=s;i--){
        for(int j=1;j<=i;j++){
                int l;
                l=b[i]-b[j]-(a[i]-a[j])*(j-1);
            if(l<=m){
                s=max(i-j+1,s);
                break;
            }
        }
    }
    cout<<s;
}
