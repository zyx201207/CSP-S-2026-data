#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans;int maxa;
bool cmp(int x,int y){return x>y;}
long long ims1(int x,int d){
    long long cnt=-1;
    if(d==m)return a[x];
    for(int i=x+1;i<=n;i++){
        cnt=max(cnt,ims1(i,d+1)&a[x]*1LL);
    }
    return cnt;
}
long long cc(long long x,double y){
    long long cnt=1;
    for(long long i=1;i<=y;i++)cnt*=x;
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];maxa=max(maxa,a[i]);
    }
    if(m==1){
        ans=maxa*1LL;
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
    }else if(n<=20){
        ans=ims1(1,1);
    }else if(maxa<4){
        sort(a+1,a+n+1,cmp);ans=a[1]*1LL;
        for(int i=2;i<=m;i++){
            ans&=a[i]*1LL;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
