#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long

int n,m;
int a[500005];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1,sum=0,ans=0;
    while(r<=n){
        while(r<=n){
            r++;
            sum+=(a[r]-a[r-1])*(r-l);
            if(sum>m||sum<0)break;
            ans=max(ans,r-l+1);
        }
        sum-=a[r]-a[l];
        l++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
