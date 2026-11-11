#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans,flag=1;
long long m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[2]-a[1]) flag=0;
    }
    if(flag==1){
        int sum=0;
        ans=1;
        for(int i=n-1;i>=1;i--){
            sum+=a[n]-a[i];
            if(sum>m) break;
            ans++;
        }
        cout<<ans;
        return 0;
    }
    a[0]=2e18+1,a[n+1]=-2e18-1;
    for(int i=n;i>=1;i--){
        if(a[i]==a[i+1]) continue;
        long long sum=0;
        int l=i-1,cnt=1;
        while(sum<=m){
            while((sum+abs(a[i]-a[l])<=m)&&(l>0)){
                sum+=abs(a[i]-a[l]);
                cnt++;
                l--;
            }
            if((sum+abs(a[i]-a[l]))>m||(l<0))break;
        }
        ans=max(ans,cnt);
        if(cnt==i){
            cout<<cnt;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
