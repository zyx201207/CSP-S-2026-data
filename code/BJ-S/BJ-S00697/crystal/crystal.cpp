#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long j=-5;
long long a[500007],b[500007];
long long num(int sit,int sp,int cnt){
    for(int i=sit-cnt;i<sit;i++){
        sp+=a[i];
    }
    return sp;
}
long long wh(int x){
    int sit=x;
    int cnt=0;
    int cost=0;
    while((cost<=m)&&(cnt<=x)){
        cost+=num(cnt,cost,sit);
        cnt++;
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    for(int i=n-1;i>=0;i--){
        a[i]=a[i]-a[i-1];
    }
    a[0]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        b[i]=wh(i);
        if(b[i]>ans){
            ans=b[i];
        }
    }
    cout<<ans;
    return 0;
}
