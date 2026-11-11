#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l;
    char c;
}a[200005];
long long sum[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long z=0,y=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
        y+=a[i].l;
        sum[i]=sum[i-1]+a[i].l;
    }
    long long len=y;
    long long l=1,r=n,ans=0;
    y--;
    while(z<=y){
        if(a[l].c==a[r].c){
            z=min(sum[l],len-sum[r-1]);
            y=len-1-z;
            if(z>=sum[l]) l++;
            if(y<sum[r-1]) r--;
        }else{
            ans+=min(sum[l],len-sum[r-1])-z;
            if(ans>len/2) ans=len/2;
            z=min(sum[l],len-sum[r-1]);
            y=len-1-z;
            if(z>=sum[l]) l++;
            if(y<sum[r-1]) r--;
        }
    }
    cout<<ans;
    return 0;
}
