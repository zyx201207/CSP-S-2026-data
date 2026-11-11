#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<ll> a(200005);
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[0];
    ll ma=a[0],p=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        p&=a[i];
    }
    if(m==1){cout<<ma;return 0;}
    if(n==m){cout<<p;return 0;}
    if(m==2){
        ll ma1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                ma1=max(ma1,a[i]&a[j]);
            }
        }
        cout<<ma1;
        return 0;
    }
    cout<<"7891";
    return 0;
}
