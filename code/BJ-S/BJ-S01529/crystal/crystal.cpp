#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long n,m,a[N],b[N],c[N];
int ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
        b[i]=b[i-1]+a[i];
    }
    for(int i=1,j=1;i<=n;){
        int sum=c[i]-a[i]*(j-1)+b[j-1];
        if(sum<=m){
            ans=max(ans,i-j+1);
            i++;
        }else{
            j++;
        }
    }
    cout<<ans;
    return 0;
}
