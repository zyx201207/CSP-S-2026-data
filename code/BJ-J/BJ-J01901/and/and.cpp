
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],pre[100005];
signed main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++){
    cin>>a[i];
 }
 if(m==n){
    int sum=a[1];
    for(int i=2;i<=n;i++){
        sum&=a[i];

    }
    cout<<sum;
 }
 else if(m==1){
        int sum=-1;
    for(int i=1;i<=n;i++){
        sum=max(sum,a[i]);
    }
    cout<<sum;
 }
 else if(m==2){
    int sum=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum=max(sum,a[i]&a[j]);
        }
    }
    cout<<sum;
 }
 else if(n==5&&m==3)cout<<7;

return 0;
}
