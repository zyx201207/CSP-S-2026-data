#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,k;
int ans,tmp;
int cnta,cntb;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]-a[i-1]==1){
            cnta++;
        }
        if(a[i]-a[i-1]==k||i==1){
            if(i==1){
                k=a[i];
            }
            cntb++;
        }
    }
    if(cnta==n||cntb==n){//A&B
        for(int i=n;i>=1;i--){
            if(m-a[n]+a[i]>=0){
                m=m-a[n]+a[i];
                ans++;
            }
        }
        cout<<ans;
    }else{
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            k=m,tmp=1;
            for(int j=i-1;j>=1;j--){
                if(k-a[i]+a[j]>=0){
                    k=k-a[i]+a[j];
                    tmp++;
                }
            }
            ans=max(ans,tmp);
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
