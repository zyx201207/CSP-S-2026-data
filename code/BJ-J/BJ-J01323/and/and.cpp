#include<bits/stdc++.h>
using namespace std;
int a[1000009],b[200009],l;
int ans=0;
void k1(int x,int y,int d){
    if(x==0 && y==0) return;
    if(x%2==1 && y%2==1)  a[d]=1;
    else  a[d]=0;
    k1(x/2,y/2,d+1);
    l=max(l,d);
}
int k2(int a[]){
    for(int i=1;i<=l;i++){
        ans+=pow(2,i-1)*a[i];
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n+1);
    k1(b[n],b[n-1],1);
    k2(a);
    for(int i=n-2;i>=n-m+1;i++){
        l=0;
        memset(a,0,sizeof(a));
        k1(ans,b[i],1);
        k2(a);
    }
    cout<<ans;
    return 0;
}
