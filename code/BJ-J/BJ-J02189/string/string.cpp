#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],n;
char c[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ll l=1,r=n;
    ll nededt=0;
    for(l=1;l<r;l++){
        ll now=0,cune=0;
        while(now<=a[l]){
            ll nnow=now+a[r];
            if(nnow>a[l]){a[r]-=(a[l]-now);if(c[r]!=c[l]){cune+=(a[l]-now);}break;}
            else if(nnow==a[l]){if(c[r]!=c[l]){cune+=a[r];}r--;break;}
            else{now=nnow;if(c[r]!=c[l]){cune+=a[r];}r--;}
        }
        nededt+=cune;
    }
    cout<<nededt;
    return 0;
}
