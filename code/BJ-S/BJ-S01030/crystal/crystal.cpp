#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],ans;
long long sum;
bool f=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
        if(i!=1&&b[i]!=b[i-1]) f=false;
    }
    if(f){
        for(int i=1;i<=n;i++){
            if(i==n){
                ans=n;
                break;
            }
            sum+=(i*b[1]);
            if(sum>m){
                ans=i;
                break;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(i+ans-1>=n) break;
            long long k=1,cnt=0;
            sum=0;
            for(int j=i;j<=n;j++){
                if(j==n){
                    cnt++;
                    break;
                }
                sum+=(k*b[j]);
                k++;
                cnt++;
                if(sum>m) break;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans;
    return 0;
}