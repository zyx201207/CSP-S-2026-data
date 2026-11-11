#include<bits/stdc++.h>
using namespace std;
long n,m;
int a[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long ans[n]={0};
    for(int i=1;i<=n;i++){
            int t=0;
        for(int j=i+1;j<=n;j++){
            t+=a[j]-a[j-1];
            ans[i]++;
            if(t==m){
                break;
            }else if(t>m){
                t-=a[j]-a[j-1];
                ans[i]--;
            }
        }
    }
    sort(ans+1,ans+n+1);
    cout<<ans[n]<<endl;
    return 0;
}
