#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
long long a[MAXN];
    char c[MAXN];
int main(){

    int n,i,take,Llen,Rlen;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=0,r=n-i;
    long long ans=0;
    while(l<=r){
        if(l==r){
            break;
        }
        long long Llen=a[i];
        long long Rlen=a[r];
        long long take=min(Llen,Rlen);
    }
    if(c[l]!=c[r]){
    ans+=take;
    }
    if(Llen==Rlen){
        l++;r++;
    }
    else if(Llen<Rlen){
        a[r]-=take;
        i++;
    }
    else{
        a[l]-=take;
        r--;
    }
    cout<<ans;
return 0;
}
