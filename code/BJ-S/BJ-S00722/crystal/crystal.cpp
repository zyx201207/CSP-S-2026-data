#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f,a[1000006],cha,f1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=i+1){
            f=1;
        }
        if(i==1){
            cha=a[0]-a[1];
        }else if(i!=0){
            if(a[i-1]-a[i]!=cha) f1=1;

        }
    }
    if(f==0){
        for(int i=0;1;i++){
            if(i*(i+1)/2>m){
                cout<<i;
                return 0;
            }else if(i*(i+1)/2==m){
                cout<<i+1;
                return 0;
            }
        }
    }
    if(a[0]<a[1]){
        cha=0-cha;
    }
    if(f1==0){
        for(int i=a[0],j=1;1;i+=cha,j++){
            if(j*(i+a[0])/2>m){
                cout<<j;
                return 0;
            }else if(i*(i+a[0])/2==m){
                cout<<j+1;
                return 0;
            }
        }
    }
    return 0;
}
