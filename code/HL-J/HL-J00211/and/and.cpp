#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=INT_MIN;
long long a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(i+m>n){
            continue;
        }
        if(m==1){
            for(int j=1;j<=n;j++){
                ans=max(ans,a[j]);
            }
            cout<<ans;
            return 0;
        }else{
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}
