#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={-1000000},ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    for(long long i=1;i<=n;i++){
        long sum=0;
        //cout<<i<<":";
        for(long long j=1;j<=i;j++){
            sum+=a[i]-a[i-j];
            if(sum>m){
                //cout<<"---"<<j;
                ans=max(ans,j);
                break;
            }
            //cout<<sum<<' ';
        }
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}
