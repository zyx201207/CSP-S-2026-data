#include<bits/stdc++.h>
using namespace std;
int main (){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,cnt=0,sum=0,ans=0;
cin>>n>>m;
int a[n];
cin>>a[n];
for(int i=1;i<=n;i++){
    if(a[i]!>=a[n]){
    a[i-1]|a[i]=sum;
    a[i]|a[i+1]=cnt;
    if(sum>cnt){
        cnt=0;

        if(sum>=ans){
            sum=ans;
            sum=0;
        }else{
            sum=0;
        }
    }else{
        if(sum<cnt){
            sum=0;
            if(cnt>=ans){
                ans=cnt;
            }else{
                cnt=0;
            }
        }
    }else{
        sum=0;
        if(cnt>=ans){
                ans=cnt;
            }else{
                cnt=0;
            }
    }
    }
    break;
}
cout<<ans;
return 0;
}
