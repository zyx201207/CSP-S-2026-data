#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=LONG_MIN;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            ans=max(ans,a[i]);
        }
    }
    else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(m==n){
        ans=a[0];
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
    }
    cout<<ans;
    return 0;
}
