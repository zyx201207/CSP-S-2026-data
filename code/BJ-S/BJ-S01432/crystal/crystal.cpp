#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,m,re=1,now=0,sum=0;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int j=n-1;j>0;j--){
        now+=(a[n]-a[j]);
        if(now>m){
            now-=(a[n]-a[j]);
            re=max(re,n-j);
            break;
        }
        if(now==m){
            re=max(n-j+1,re);
            break;
        }
    }
    sum=re-1;
    for(int i=n-1;i>1;i--){
        now-=(a[i+1]-a[i])*sum;
        for(int j=i-sum;j>0;j--){
            now+=(a[i]-a[j]);
            if(now>m){
                now-=(a[i]-a[j]);
                re=max(re,i-j);
                sum=i-j-1;
                break;
            }
            if(now==m){
                sum=i-j;
                re=max(i-j+1,re);
                break;
            }
        }
    }
    cout<<re<<endl;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
