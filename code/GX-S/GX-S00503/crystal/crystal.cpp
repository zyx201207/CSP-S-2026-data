#include<bits/stdc++.h>
using namespace std;
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
int n,m,ans,sum,a[100000];
int main(){
    ans=0;
    sum=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];

if(a[n/2]-a[n/2-1]>=a[n/2]-a[n/2-2]&&a[n/2]-a[n/2-1]>=a[n/2+1]-a[n/2]&&a[n/2]-a[n/2-1]>=a[n/2+2]-a[n/2]){
       ans=a[n/2]-a[n/2-1];
       if(m-ans>=0);
       m=m-ans;
       sum++;
       if(a[n/2]-a[n/2-2]>=a[n/2]-a[n/2-1]&&a[n/2]-a[n/2-2]>=a[n/2+1]-a[n/2]&&a[n/2]-a[n/2-2]>=a[n/2+2]-a[n/2]){
       ans=a[n/2]-a[n/2-2];
       if(m-ans>=0);
       m=m-ans;
       sum++;
       ans=0;

       }



    }

cout<<sum;
return 0;
}
