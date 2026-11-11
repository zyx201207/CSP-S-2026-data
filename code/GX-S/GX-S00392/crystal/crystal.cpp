#include<bits/stdc++.h>
using namespace std;
long long n,a[600000],m,c[6000000],zk,by=1,ans,z,tiao;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
        by=1;
        while(a[i+by]==a[i]){
            by+=1;
            tiao+=1;
        }
        for(long long y=i;y>=1;y--){
                if(zk*2+c[y]<=m){
                    zk=zk*2+c[y];
                    by+=1;
                }else{
                if(by>ans){
                    ans=by;
                }
                }
        }
        zk=0;
        if(tiao>0)
        i+=tiao+1;
        tiao=0;
    }
    cout<<ans;

return 0;
}
