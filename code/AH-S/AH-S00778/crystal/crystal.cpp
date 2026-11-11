#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cin>>n>>m;
    long long a[n],b;
    bool rel=true;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<n;i++){
        for(long long j=i;j<n;j++){
            if(a[i]>=a[j]){
                b=a[j];
                a[j]=a[i];
                a[i]=b;
            }
        }
    }
    for(long long i=0;i<n-2;i++){
        if((a[i+1]-a[i])!=a[i+2]-a[i+1]) rel=false;
    }
    if(rel){
        long long ans=0,time=1,c=a[1]-a[0];
        for(long long i=c;i<n*c;i+=c){
            if(ans<=m&&ans+i*2<=m) {
                ans+=(i*2);
                time+=2;
            }
            else if(ans<=m&&ans+i<=m){
                ans+=i;
                time++;
            }
            else i=n*c;
        }
        cout<<min(time,n)<<endl;
    }
    else{
        long long sum[n]={0},mum[n]={0};
        for(long long i=n-1;i>=0;i--){
            for(long long j=i;j>=0;j--){
                if(sum[n-1-i]<=m&&sum[n-1-i]+a[i]-a[j]<=m){
                  sum[n-1-i]+=a[i]-a[j];
                  mum[n-1-i]++;
                }
            }
        }
        long long z=0;
        for(long long i=0;i<n;i++){
            for(long long j=i;j<n;j++){
                if(mum[i]>=mum[j]){
                    z=mum[j];
                    mum[j]=mum[i];
                    mum[i]=z;
                }
            }
        }
    cout<<mum[n-1]<<endl;
    }
    return 0;
}
