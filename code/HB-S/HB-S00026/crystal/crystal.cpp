#include<bits/stdc++.h>
using namespace std;
long long sz[500100];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sz[i];
    }
    sort(sz+1,sz+1+n);
    unsigned long long ans=1,cnt=0;
    unsigned long long l=1,r=1;
    while(l<=r&&r<n){
        r++;
        cnt+=(sz[r]-sz[r-1])*(r-l);
        //cout<<l<<" "<<r<<" "<<cnt<<endl;
        while(cnt>m&&l<=r){
            cnt-=sz[r]-sz[l];
            l++;
            //cout<<l<<" "<<r<<" "<<cnt<<endl;
        }
        if(cnt<=m){
            ans=max(ans,r-l+1);
            //cout<<l<<" "<<r<<" "<<cnt<<endl;
        }
    }
    cout<<ans;
    return 0;
}