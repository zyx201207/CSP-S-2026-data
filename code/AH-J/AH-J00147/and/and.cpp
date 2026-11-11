#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,i,j,k,s=0,mx=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        s=a[1];
        for(i=2;i<=n;i++){
            s&=a[i];
        }
    cout<<s;
    }
    else if(m==2){
        for(i=1;i<n;i++){
            s=a[i];
            for(j=i+1;j<=n;j++){
                s&=a[j];
                if(s>mx) mx=s;
                s=a[i];
            }
        }
        cout<<mx;
    }
    else if(m==1){
        for(i=1;i<=n;i++){
        if(a[i]>mx) mx=a[i];
        }
        cout<<mx;
    }
    else {
        for(i=1;i<=n;i++){
            s=1;
            for(j=1;j<=n;j++){
                if(i==j) continue;
                s&=a[j];
            }
            if(s>mx) mx=s;
        }
        cout<<mx;
    }
    return 0;
}
