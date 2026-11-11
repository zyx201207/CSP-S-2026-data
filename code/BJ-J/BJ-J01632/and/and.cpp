#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,maxx=-5,A,maxi=1,Ai;
    long long a[200010];
    bool flagA=false,flagB=false;
    cin>>n>>m;
    if((n&n-1)==0){
        flagB=true;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(maxx<a[i]){
            maxx=max(maxx,a[i]);
            maxi=i;
        }
        if((a[i]+1&a[i])==0){
            flagA=true;
            A=a[i];
            Ai=i;

        }
        if(flagB){
            if(a[i]!=i-1){
                flagB=false;
            }
        }

    }
    //sort(a+1,a+1+n);
    //for(long long i=1;i<=n;i++){
    //    swap(a[i],a[n-i+1]);
    //}
    if(m==1){
        cout<<maxx;
//        cout<<"run";
  //      cout<<m;
        return 0;
    }
    if(flagB){
        sort(a+1,a+1+n);
        long long ans=maxx;
        for(long long i=1;i<=m-1;i++){
            ans=(ans&a[n-i]);
        }
        cout<<ans;
        return 0;
    }
 //   if(flagA){
   //     if(A!=maxi){
   //         long long mi;
//            while(A&pow(10，mi)!=0){
  //              mi++;
    //        }
      //      for(int i=1;i<=n;i++){
//
  //          }
     //       cout<<(a[maxi]&a[Ai]);
       //     return 0;

        //}
       // else{
        //    sort(a+1,a+1+n);
          //  cout<<(a[n-1]&a[Ai]);
            //return 0;
        //}
   // }
   long long ans,ans1;
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            ans1=(a[i]&a[j]);
            ans=max(ans1,ans);
        }
    }
    cout<<ans;
    return 0;
}
