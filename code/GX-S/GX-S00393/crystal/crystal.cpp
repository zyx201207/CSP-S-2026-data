#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+1]={0},c[n+1]={0};
    c[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n);
    for(int i=1;i<n;i++){
        int x=n,vct=1;
        for(int j=i-1;j>=0;j--){
                int y=a[i]-a[j];
            if(y<=n){
                x=x-y;
                vct++;
            }
        }
        c[i]+=vct;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,c[i]);
    }cout<<ans;
return 0;
}
