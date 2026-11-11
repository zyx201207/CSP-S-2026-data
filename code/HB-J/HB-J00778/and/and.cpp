#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    ll n,m;cin>>n>>m;
    ll max1=0;
    ll a[10001]={};
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max1){
            max1=a[i];
        }
    }if(m==1){
        cout<<max1;
    }if(m==2){
        int max2=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]&a[j]>max2){
                    max2=a[i]&a[j];
                }
            }
        }
        cout<<max2;
    }
    return 0;
}
