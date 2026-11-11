#include<bits/stdc++.h>
using namespace std;
long long n,a[10000000],num=0;
char b[1000000];
int main(){
     freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   long long left,right;
   cin>> n;
   for(int i=1;i<=n;i++){
   cin>>a[i]>>b[i];
   }
   if(n%2==0){
    left=n/2;
    right=n/2+1;
    while(left!=0&&right!=n+1){
    if(b[left]!=b[right]){
        num+=min(a[left],a[right]);
        a[left]-=min(a[left],a[right]);
        a[right]-=min(a[left],a[right]);
    } else{
    a[left]-=min(a[left],a[right]);
        a[right]-=min(a[left],a[right]);
        }
    if(a[left]==0) left--;
    if(a[right]==0) right++;
    }
   }
   if(n%2==1){
        left=n/2;
        right=n/2+2;
        if(a[n/2+1]>=a[left]){
                num+=a[left];
            a[left]-=a[left];
        } else if(a[n/2+1]>=a[right]){
            num+=a[right];
            a[left]-=a[right];
        }
    while(left!=0&&right!=n+1){
    if(b[left]!=b[right]){
        num+=min(a[left],a[right]);
        a[left]-=min(a[left],a[right]);
        a[right]-=min(a[left],a[right]);
    } else{
        a[left]-=min(a[left],a[right]);
        a[right]-=min(a[left],a[right]);
    }
    if(a[left]==0) left--;
    if(a[right]==0) right++;
    }
   }
   cout<<num;
return 0;
}
