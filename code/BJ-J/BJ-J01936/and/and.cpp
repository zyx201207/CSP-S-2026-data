#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //xiao R shi shazi
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)cout<<a[n];
    if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        long long ans=0;

        for(int i=1;i<=n;i++){
            long long ct=0;
            for(int j=1;j<=n;j++){
                if(i!=j){
                    if(ct==0)ct=a[j];
                //    cout<< a[j]<<endl;
                }
                else ct=ct&a[j];

            }
            if(ct>=ans)ans=ct;
        }
        cout<<ans;
        return 0;
    }
    if(m!=2){
        cout<<1;
        return 0;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                if((a[i]&a[j])>ans){
                    ans=a[i]&a[j];
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
