#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int s(int a,long long b,int c){
    while(a!=0){
        b+=a%2*c;
        a/=2;c*=10;
    }
    return b;
}
int an(long long a,long long b,int x,int c,int cnt){
    x=a+b;
    while(x!=0){
        if(x%10==2)cnt+=c;
        x/=10;c*=2;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=s(a[i],0,1);
    }int ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,an(a[i],a[j],0,1,0));
        }
    }
    cout<<ans;
    return 0;
}
