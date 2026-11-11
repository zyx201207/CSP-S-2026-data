#include<bits/stdc++.h>
using namespace std;
int a[200010],ans;
int solve(int a,int b){
    ans=0;
    int k=0;
    map<int,int> mp1,mp2,mp3;
    while(a){
        mp1[k]=a%2;
        a/=2;
        k++;
    }
    int k1=0;
    while(b){
        mp2[k1]=b%2;
        b/=2;
        k1++;
    }
   for(int i=0;i<=min(k,k1);i++){
        if(mp1[i]==1&&mp2[i]==1){
            mp3[i]=1;
        }else{
            mp3[i]=0;
        }
   }
   for(int i=0;i<mp3.size();i++){
        ans+=mp3[i]*pow(2,i);
   }
   return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int p=0;
    sort(a+1,a+n+1,greater<int>());
    p=a[1];
    for(int i=2;i<=m;i++){
        p=solve(p,a[i]);
    }
    //cout<<a[1]<<" "<<a[2];
    //cout<<solve(a[1],a[2]);
    cout<<p;
    return 0;
}
