#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=200000+10;
int a[maxn];
int n,m,ans;
int main(){
 freopen("add.in","r",stdin);
freopen("add.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=max(sum,a[i]);
        }
        cout<<sum;
        return 0;
    }if(m==2){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int he=a[i]^a[j];
                sum=max(sum,he);
            }
        }
        cout<<sum;
        return 0;
    }if(m==n){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum^a[i];
        }
        cout<<sum;
        return 0;
    }else{
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ans=max(ans,ans^a[j]);

        }
    }
    }
    cout<<ans;
    return 0;
}
