#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
long long n,L;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n==1) {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=1;i<=n/2;i++){
        if(c[i]!=c[n+1-i]){
            ans+=a[i];

        }
    }
    cout<<ans;
    return 0;
}