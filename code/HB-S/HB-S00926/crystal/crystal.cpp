#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500006],sum=0,p=0,ans=0;
    bool _=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[0]=a[1];
    long long h=m;
    for(int i=1;i<=n;i++){
        sum=(a[i]-a[i-1])*(p++);
        //cout<<h<<' '<<ans<<" and "<<a[i]<<' '<<p<<' '<<i<<" and "<<sum<<endl;
        if(h<sum){
            ans=max(ans,p-1);
            p=0;
            h=m;
            sum=0;
            _=false;
        }else{
            h-=sum;
        }
    }
    if(_)ans=n;
    cout<<ans;
    return 0;
}
