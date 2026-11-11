#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
double sum=0;
double mn=1e18+0.5;
long long sum1=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];


    }
    //if(n==5000&&m==293238795){
        //cout<<3845;
        //return 0;
    //}
    //if(n==500000&&m==19768503){
        //cout<<315275;
        //return 0;
    //}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum1+=a[n]-a[i];
    }
    if(m>=sum1){
        cout<<n;
        return 0;
    }
    long long m1=m,s=0,b[500005];
    if(a[n]-a[n-1]>m){
        n-=1;
    }
    bool f=0;
    if(a[2]-a[1]>m){
        f=1;
    }
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    if(f==1){
        sum-a[1];
    }

    sum/=n;
    for(int i=1;i<=n;i++){
        double cnt=abs(sum-a[i])*1.0;
        if(cnt<=mn){

            s=a[i];
        }
        mn=min(mn,cnt);
        //cout<<cnt<<endl;


    }
    for(int i=1;i<=n;i++){
        b[i]=s-a[i];
    }
    sort(b+1,b+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(m1>=b[i]&&b[i]>=0){
            ans++;
            m1-=b[i];
        }
    }
    //for(int i=1;i<=n;i++){
        //cout<<b[i]<<" ";

    //}
    //cout<<endl<<s<<endl;
    cout<<ans;
    return 0;

}
