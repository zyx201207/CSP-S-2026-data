#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005],b[200005];
long long ans=0;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        b[n-i]=a[i];
    }

    int maxo=-1;
    int o;
    for(int i=1;i<=n;i++){
        if(b[i]-b[i+1]>maxo) {
            maxo=b[i]-b[i+1];
            o=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(i==1) ans+=b[o]&b[o+1];
        ans=ans&b[o-i];
    }
    cout << ans;
    return 0;
}
