#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[50005],ans=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long c=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(m-c*i>=0){
            m=m-c*i;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
