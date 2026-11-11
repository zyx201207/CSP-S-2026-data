#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll a[n];
    int max=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max){
        max=a[i];
        }
    }
    int maxand=0;
    int sum=0;
    if(m!=2){
        cout<<max;
        return 0;
    }
    else if(m==2){
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
                sum=a[i]&a[j];
            if(sum>maxand){
                maxand=sum;
            }
        }
    }
    cout<<maxand;
   }
    return 0;
    }
