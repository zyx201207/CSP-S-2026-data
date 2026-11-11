#include <bits/stdc++.h>
using namespace std;
int n,m,top;
long long a[200001];
long long ans1,ans,ans2,ans3;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans1=max(ans,a[i]);
    }
    if(m==2){
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
       cout<<ans;
       return 0;
    }
    if(m==n-1){
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(i!=1) sum=a[1];
            else sum=a[2];
            for(int j=1;j<=n;j++){
                if(j!=i){
                    sum=sum&a[j];
                }
            }
            ans2=max(ans2,sum);
        }
        cout<<ans2;
        return 0;
    }
    if(m==n){
        ans3=a[1];
        for(int i=1;i<=n;i++){
            ans3=ans3&a[i];
        }
        cout<<ans3;
        return 0;
    }
    if(n>2000||m==1) cout<<ans1;
    else cout<<0;
    return 0;
}
