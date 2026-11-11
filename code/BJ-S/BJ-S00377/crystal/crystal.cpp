#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[100005];
int main(){
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        m-=i*(a[i+1]-a[i]);
        if(m<0){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
