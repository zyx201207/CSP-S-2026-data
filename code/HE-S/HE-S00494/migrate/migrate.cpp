#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
void v(){
    ll n,d,tmp=0;
    cin>>n>>d;
    ll x[n],a[10000];
    for(ll i=0;i<n;i++) cin>>x[i];
    for(ll i=0;i<n;i++){
        for(int k=1;k<=d;k++){
            for(int j=i;j<n;j++){
                tmp=x[j]+k;
                if(tmp==x[n-1]) a[j]++;
            }
        }

    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++) v();

    return 0;
}
