#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500005],cnt[500005];
long long m;
int sum;
long long ans;
int num;
int h;
bool cmp(int a,int b){
    return a>b;
}
int flat;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]-1!=a[i-1])flat=1;
    }
    if(flat==0){
        for(int i=1;i<=n;i++){
            ans+=a[i];
            if(ans>m){
                ans-=a[i];
                cout<<ans;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cnt[i]+=a[i]-a[j];
        }
    }
    for(int i=1;i<=n;i++){
            //cout<<cnt[i];
        if(cnt[i]<=m){
            if(cnt[i]>=ans){ans=cnt[i];h=i;}
        }

    }

//    for(int i=1;i<=n;i++){
 //       for(int j=i+1;j<=n;j++){
   //         sum+=a[i]-a[j];
 //           if(sum<=m){
  //              num++;
   //         }
  //      }
   //     if(num>ans){
  //          ans=num;
  //          h=i;
  //      }
        //cout<<a[i]<<" "<<num<<" "<<ans<<endl;
   //     num=0;
   //     sum=0;

   // }

    cout<<h;
    return 0;
}
