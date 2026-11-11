#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,m;
    cin>>n;
    m=n;
    vector<long long> a(n+1);
    vector<char> c(n+1);
    unsigned long long sum=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    long long b=a[0],d=a[n-1],e;
    int i=0;
    int j=n-i-1;
    while(1){
      //  cout<<1;
        if(j<=i+1){
            break;
        }
        if(b>d){
            if(c[i]!=c[j]){
                ans+=d;
            }
            sum-=2*d;
            e=b;
            b-=d;
            d-=e;
            while(1){
                if(d>0 || j==i+1){
                    break;
                }
                j--;
                d+=a[j];
                if(d<=0 && c[i]!=c[j]){
                    ans+=a[j];
                }
                if(d>0 && c[i]!=c[j]){
                    ans+=a[i]-d;
                }
            }
        }else{
            if(b<d){
                if(c[i]!=c[j]){
                    ans+=b;
                }
                e=b;
                b-=d;
                d-=e;
                while(1){
                    if(b>0 || j==i+1){
                        break;
                    }
                    i++;
                    b+=a[i];
                    if(b<=0 && c[i]!=c[j]){
                        ans+=a[i];
                    }
                    if(b>0 && c[i]!=c[j]){
                        ans+=a[i]-b;
                    }
                }
            }else{
                if(c[i]!=c[j]){
                    ans+=b;
                }
                i++;
                j--;
                if(j==i+1){
                    break;
                }else{
                    b=a[i];
                    d=a[j];
                    sum-=b+d;
                }
            }
        }
    }
//    for(int i=0,j=n-i-1;sum>=0;){
//        if(c[i]==c[j]){
//            sum-=2*min(a[i],a[j]);
//            b-=c[j];
//            while()
 //           j--;
 //       }
  //  }
   // while(j>i){
        //sum-=2*min(b,d);
      //  if(c[i]!=c[j]){
    //        ans+=min(b,d);
  //      }
//        e=b;
     //   b-=d;
    //    d-=e;
    //    if(b==sum || d==sum){
       //     break;
     //   }
   //     cout<<sum<<" "<<
 //       while(b<=0 && j>i){
   //   //      e=b;
      //      i++;
    //        b+=a[i];
  //          if(c[i]!=c[j]){
//                if(b<=0){
                //    ans+=a[i];
              //  }else{
            //        ans+=a[i]-b;
          //      }
        //    }
      //  }
    //    while(d<=0 && j>i){
  //          j--;
        //    d+=a[j];
      //      if(c[i]!=c[j]){
    //            if(d<=0){
    //                ans+=a[j];
    //            }else{
   //                 ans+=a[j]-d;
   //             }
  //          }
  //      }
    //    if(c[i]=c[j]){
   //         sum-=2*min(a[i],a[j]);
   //         b-=a[j];
   //         while(b<=0){
   //             i++;
   // //            b+=a[i];
   //         }
   //         j--;
  //      }
   // }
    cout<<ans<<endl;

    return 0;
}
