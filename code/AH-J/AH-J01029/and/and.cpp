#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool can[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if((!can[j])&&(a[j]&(1<<i))){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if((!can[j])&&(a[j]&(1<<i))){
                }else{
                    can[j]=1;
                }
            }
            ans+=(1<<i);
        }
    }
    cout<<ans<<endl;




    return 0;
}
