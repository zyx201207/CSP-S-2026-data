#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool flag=false;
    bool flag1=false;
    int max_a=0,min_a=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        min_a=min(min_a,a[i]);
        max_a=max(max_a,a[i]);
        if(llabs(a[i])>100){
            flag=true;
        }
        if(a[i]!=i){
            flag1=true;
        }
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        int ans=0;
        for(int i=1;i<=n;i++){
            int t=m;
            int ans1=1;
            for(int j=1;j<i;j++){
                if(t>=(a[i]-a[j])){
                    t-=(a[i]-a[j]);
                    ans1++;
                }
            }
            ans=max(ans,ans1);
        }
        cout<<ans<<endl;
    }else if(!flag1){
        int t=sqrt(2.0*m);
        if(t*(t+1)<=m){
            cout<<t+1;
        }else{
            cout<<t;
        }
    }else if(!flag){
        int ans=0;
        for(int i=a[1]+1;i<=a[n];i++){
            int t=upper_bound(a+1,a+n+1,i)-a-1;
            int ans1=0;
            int t1=m;
            for(int j=t;j>=1;j--){
                if(t1>=(i-a[j])){
                    t1-=(i-a[j]);
                    ans1++;
                }
            }
            ans=max(ans,ans1);
        }
        cout<<ans<<endl;
    }else{
        cout<<min(n,m/(a[2]-a[1]))+1<<endl;
    }
    return 0;
}
