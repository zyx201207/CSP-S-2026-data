#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long a[500005];
long long dis[500005];
long long sen;//to tell whether we should make the mid bigger or smaller
long long l=1000000000005,r=-1000000000005;
long long sum;
long long ans;
long long res;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    for(int i=l;i<=r;i++){

        for(int j=1;j<=n;j++){
            dis[j]=abs(a[j]-i);
        }
        sort(dis+1,dis+n+1);
        res=0;
        sum=0;
        for(int j=1;j<=n;j++){
            if(sum+dis[j]<=m){
                sum+=dis[j];
                res++;
            }
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}
