#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
            flag=false;
            break;
        }
    }
    if(flag==false){
        sort(a+1,a+n+1);
        long long ans=0,sum=0;
        for(int i=1;i<=n;i++){
            sum=(a[i]-a[i-1])*(i-1)+sum;
            if(sum<=m)ans=i;
        }
        cout<<ans;
        return 0;
    }
    else{
        long long sum=0,ans=0;
        for(int i=1;i<=n;i++){
            sum=0;
            for(int j=i;j<=n;j++){
                sum=(a[j]-a[j-1])*(j-i)+sum;
                if(sum<=m)ans=j-i+1;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
