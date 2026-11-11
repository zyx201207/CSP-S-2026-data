#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[500005],is=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==1) q=a[i]-a[i-1]；
        if(a[i]-a[i-1]!=q) is=0;
    }
if(is==1){
for(int i=1;i!=0;i++){
w=(1+i)*i/2*q;
if(w>m){
cout<<i;
return 0;
}
}
}
    sort(a,a+n);
    for(int i=0;i<n;i++){
        long long sum=0,cnt=1;
        for(int j=i;j<n;j++){
            if((a[j+1]-a[j])*(j+1-i)+sum<=m) ans=max(ans,cnt),cnt++,sum+=(a[j+1]-a[j])*(j+1-i);
            else{
                ans=max(ans,cnt);
                break;
            }
        }
    }
    cout<<min(n,ans);
    return 0;
}

