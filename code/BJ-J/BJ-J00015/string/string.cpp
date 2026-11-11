#include<bits/stdc++.h>
using namespace std;
long long n;struct node{
    long long x;char a;
}r1[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;long long h=0;
    for(int i=0;i<n;i++){
       cin>>r1[i].x>>r1[i].a;h+=r1[i].x;
       //cout<<r1[i].x<<" "<<r1[i].a<<"\n";
    }
    
    long long ans=0,f;
   long long k=0,l=0,r=n-1;
 
       while(l<r){
           if(r1[l].a!=r1[r].a){
               if(r1[l].x<r1[r].x){
                   ans+=r1[l].x;r1[r].x=r1[r].x-r1[l].x;
                   l++;
               }else if(r1[l].x==r1[r].x){
                   ans+=r1[r].x;r--;l++;
               }else{
                   ans+=r1[r].x;r1[l].x=r1[l].x-r1[r].x;
                   r--;
               }
           }
           else{
              if(r1[l].x<r1[r].x){
                   r1[r].x=r1[r].x-r1[l].x;
                l++;
               }else if(r1[l].x==r1[r].x){
                   r--;l++;
               }else{
                   r1[l].x=r1[l].x-r1[r].x;
                   r--;
               }
           }
           if(l>=r)break;
           
       }
    cout<<ans;
    return 0;
}