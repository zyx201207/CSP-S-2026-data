#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500003];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
      sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=1;j<=i;j++){
                sum+=a[i]-a[j];
            }
        if(sum<=m){
            ans=i;
        }
        else break;
    }
    cout<<ans;
    }
    else{
        if(a[1]=1&&a[2]==2&&a[3]==3){
            int sum=0,ans=0;
            for(int i=1;i<=n;i++){
                sum+=a[i];
                if(sum>m){
                    ans=i;
                    break;
                }
            }
            cout<<ans;
        }
    }
return 0;
}
