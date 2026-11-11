#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300000];
long long b,he[300000],ans;

string z;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
     //     he[i]=a[i]&he[i-1];

    }
    if(m==1){
        for(int i=1;i<=n;i++){
        if(a[i]>ans)
            ans=a[i];


          }
          cout<<ans;
    }else if(m==2){
    for(int i=1;i<n;i++){
        for(int y=i+1;y<=n;y++){
          if(a[i]&a[y]>ans){
            ans=a[i]&a[y];
          }




        }
    }
       cout<<ans;
    }//else if(m==n-1){

      //  }
    //}

   return 0;
}

