#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000005],Max,num;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) continue;
        long long fun=m,ans=1,l=i;
        while(a[l+1]==a[l]){
            ans+=1;
            l+=1;
        }
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=fun){
                fun-=(a[i]-a[j]);
                ans+=1;
            }
        }
        num=max(ans,num);
    }
    cout<<num;
    return 0;
}
