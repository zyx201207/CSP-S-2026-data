#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a[500005],b[500005],ans=1;
bool f=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
        if(f&&i!=1&&b[i]!=b[i-1])f=0;
    }
    if(f){
        for(ans=1;ans<=n&&sum<=m;ans++)sum+=b[1]*ans;
        if(ans==n+1)ans=n;
        cout<<ans;
        return 0;
    }
    for(int i=1,j=2;j<=n;j++){
        sum+=(j-i)*b[j];
        if(sum<=m&&ans<j-i+1)ans=j-i+1;
        if(sum>m){
            sum-=a[j]-a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
