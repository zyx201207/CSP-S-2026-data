#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=a[i]-a[i-1];
    }
    int ans=0,sum=0;
    for(int i=1;i<=n;i++){
        sum+=x*i;
        if(m<sum){
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}
