#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    string b;
}f[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   long long n,ans=0;
   cin>>n;
   for(int i=0;i<n;i++){
        cin>>f[i].a;
        cin>>f[i].b;
   }
   int i=0;
   int j=n-1;
   while(i<=j){
    if(f[i].b!=f[j].b){
        if(f[i].a>f[j].a){
            ans+=f[j].a;
            f[i].a-=f[j].a;
            j-=1;
        }else if(f[i].a<f[j].a){
            ans+=f[i].a;
            f[j].a-=f[i].a;
            i+=1;
        }else{
            ans+=f[i].a;
            j-=1;
            i+=1;
        }
    }else{
        if(f[i].a>f[j].a){
            f[i].a-=f[j].a;
            j-=1;
        }
        if(f[i].a<f[j].a){
            f[j].a-=f[i].a;
            i+=1;
        }
        if(f[i].a==f[j].a){
            j-=1;
            i+=1;
        }
    }
   }
   cout<<ans;
    return 0;
}
