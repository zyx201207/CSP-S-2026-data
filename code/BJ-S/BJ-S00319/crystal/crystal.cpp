#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
//long long max1=LLONG_MIN,min1=LLONG_MAX;
long long P(long long b){
    long long ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<b){
            //cout<<ans<<' '<<i<<endl;
            ans+=b-a[i];
        }else{
            break;
        }
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
  //  long long ans2=LLONG_MAX;
    scanf("%lld %lld",& n,& m);
    //cout<<n<<' '<<m<<endl;
    for(long long i=0;i<n;i++){
        ////cin>>a[i];
        scanf("%lld",& a[i]);
       // if(a[i]<=26) ans2++;
      //  a[i+n]=a[i];
        //max1=max(max1,a[i]);
        //min1=min(min1,a[i]);
    }
   // cout<<ans2<<endl;
    //n*=2;
    //m*=2;
    sort(a,a+n);
    // long long l=min1,r=max1;
    long long l=a[0],r=a[n-1];
  //  cout<<l<<' '<<r;
    while(l<r){
        long long mid=r-(r-l)/2;
      //  cout<<mid<<' '<<l<<' '<<r<<endl;
        long long tmp=P(mid);
        if(tmp<=m){
          //      cout<<'!'<<tmp<<' '<<m<<endl;
            l=mid;
        }else{
            r=mid-1;
        }
    }
  //  cout<<l<<' '<<r<<endl;
    long long ans1=0;
    for(long long i=0;i<n;i++){
        if(a[i]<=l) ans1++;
        else break;
    }
    //315829 313324  313275
    cout<<ans1;
    return 0;
}
