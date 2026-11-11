#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int unsigned long long
int n,m,a[200001],b[32],bj[32],cs[32],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=0;i<=30;i++) b[i+1]=pow(2,i);
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        for(int j=30;j>=1;j--){
            if(a[i]>=b[j]){
                a[i]-=b[j];
                bj[j]=1;
                cs[j]++;
            }else if(cs[j]<=m) bj[j]=0;
        }
    }for(int i=30;i>=1;i--){
        ans=ans*2+bj[i];
    }cout<<ans;
    return 0;
}
