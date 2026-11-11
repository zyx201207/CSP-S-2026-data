#include<bits/stdc++.h>
using namespace std;
long long a[200020],ans;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)cout<<a[n];
    else if(m==n){
        ans=LONG_MAX;
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]){
                ans=a[i];
            }
        }
        if(ans!=0){
            cout<<ans;
        }
    }
    else{
        ans=a[n]&a[n-1];
        cout<<ans;
    }
    return 0;
}