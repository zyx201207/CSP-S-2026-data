#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,j=1;
    long long ans=0,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i-1]=a[i]-a[i-1];
    }
    sort(b+1,b+n);
    while(m){
        if(m>=b[j]&&j<n){
            m--;
            ans++;
            j++;
        }else{
            break;
        }
    }
    cout<<ans;
    return 0;
}
