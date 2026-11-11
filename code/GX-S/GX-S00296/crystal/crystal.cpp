#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long arr[500005];
int xz(int c){
    unsigned long long ans=0;
    for(int i=1;i<=n-1;i++){
        ans=(arr[n]-arr[i]+c)*((arr[n]-arr[i])/c)/2;
        if(ans<=m) return ((arr[n]-arr[i])/c)+1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    bool A=true,B=true;
    cin>>arr[1]>>arr[2];
    if(arr[1]!=1||arr[2]!=2) A=false;
    int c=abs(arr[1]-arr[2]);
    for(int i=3;i<=n;i++){
        cin>>arr[i];
        if(arr[i]!=i) A=false;
        if(abs(arr[i]-arr[i-1])!=c) B=false;
    }
    if(A){
        cout<<xz(1);
        return 0;
    }
    if(B){
        cout<<xz(c);
        return 0;
    }
    sort(arr+1,arr+1+n);
    int ans=0;
    long long cnt;
    int sum=0;
    for(int i=2;i<=n;i++){
        cnt=m;
        sum=0;
        for(int j=i-1;j>=1;j--){
            if(cnt-(arr[i]-arr[j])>=0){
                cnt-=(arr[i]-arr[j]);
                sum++;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans+1;
    return 0;
}
