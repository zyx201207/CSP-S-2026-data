#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long ans;
    for(int i=1;i<=n/2;i++){
        if(a[i]!=a[n-i+1]){
            if(a[i]>a[n-i+1]){
                ans+=a[i];
                a[i+1]-=a[i]-a[n-i+1];
            }
            else {
                ans+=a[n-i+1];
                a[n-i]-=a[n-i+1]-a[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
