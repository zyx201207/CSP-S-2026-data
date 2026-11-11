#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        ll mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
        return 0;
    }else if(m==2){
        ll mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j){
                    continue;
                }
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
        return 0;
    }else if(n==m){
        ll ans=a[0];
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==n-1){
        ll ans=a[0];
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
        ll cnt=0;
        for(int i=1;i<n;i++){
            ans=ans&a[i];
            cnt=max(ans,cnt);
            ans=ans&a[i];
        }
        cout<<cnt;
        return 0;
    }
	return 0;
}
