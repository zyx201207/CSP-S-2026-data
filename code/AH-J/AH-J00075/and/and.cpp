#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],mx,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
        if(i==0) ans=a[i];
        ans&=a[i];
    }
    if(m==1) cout<<mx;
    else if(m==n) cout<<ans;
    else if(m==2){
        mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
    }else if(m==3){
        mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    mx=max(mx,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<mx;
    }
    return 0;
}
