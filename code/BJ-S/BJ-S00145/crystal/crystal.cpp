#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,cnt=1,a[N],c,sum,mx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w)",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        sum=0,cnt=1;
        for(int len=1,r=l+len;r<=n&&sum+len*(a[r]-a[r-1])<=m;sum+=len*(a[r]-a[r-1]),len++,r++,cnt++)
        cout<<len<<" "<<sum<<" "<<a[r]-a[r-1]<<" "<<a[r]<<" "<<a[r-1]<<" "<<sum+(len+1)*(a[r]-a[r-1])<<"\n";
        mx=max(mx,cnt);
    }
    //c=a[2]-a[1];
    //for(int i=1;i<=n;i++){
    //    if(m>=sum+(i-1)*c){
    //        sum+=(i-1)*c;
    //        cnt++;
    //    }
    //}
    cout<<mx;
    return 0;
}
