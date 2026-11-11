#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],ans;
bool check(int x){
    long long cnt=m;
    for(int i=1;i<x;i++){
        if(cnt-(a[x]-a[i])>=0){
            cnt-=(a[x]-a[i]);
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f=0,f2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3){
            f=1;
        }
        if(a[i]!=i){
            f2=1;
        }
    }
    sort(a+1,a+1+n);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            long long cnt=m,sum=1;
            for(int j=i-1;j>=1;j--){
                if(cnt-a[i]+a[j]>=0){
                    cnt=cnt-a[i]+a[j];
                    sum++;
                }else{
                    break;
                }
            }
            ans=max(ans,sum);
        }
        cout<<ans;
        return 0;
    }
    if(f2==0){
        long long sum=0;
        for(int i=2;i<=n;i++){
            sum=sum+i-1;
            if(sum>m){
                cout<<i-1;
                break;
            }
        }
        return 0;
    }
    if(f==0){
            long long sum=0;
        for(int i=2;i<=n;i++){
            sum+=(a[i]-a[i-1])*(i-1);
            if(sum>m){
                cout<<i-1;
                break;
            }
        }
        return 0;
    }

    long long l=0,r=n;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
