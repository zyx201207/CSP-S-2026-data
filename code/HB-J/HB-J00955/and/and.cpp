#include<bits/stdc++.h>
using namespace std;
int n,m,max_=-0x3ff,ans,tmp;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ans=a[1]%2;
    if(m==1){
        sort(a,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(i==j)
                    continue;
                tmp=a[i]&a[j];
                max_=max(max_,tmp);
            }
        cout<<max_;
        return 0;
    }
    if(m==3){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++){
                    if(i==j||i==k||k==j)
                        continue;
                    tmp=a[i]&a[j]&a[k];
                    max_=max(max_,tmp);
                }
        cout<<max_;
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
    cout<<ans;
    return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)
                    continue;
                ans=ans&a[i];
            }
            max_=max(max_,ans);
            ans=a[1]%2;
        }
        cout<<max_;
        return 0;
    }
    return 0;
}
