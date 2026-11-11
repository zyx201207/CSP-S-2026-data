#include<bits/stdc++.h>
#define int long long
#define intt __int128
using namespace std;
int en[500003];
int l,r;
bool cmp(int i,int j){
    return i<j;
}
signed main(){
    int i,m,n;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>en[i];
    }
    sort(en+1,en+1+n,cmp);
    intt sum=0;
    int ans=0;
    int l=1,r=0;
    for(i=1;i<=n;i++){
        sum=sum+(en[i]-en[i-1])*(r-l+1);
        r++;
        while(sum>m){
            int u=en[l];
            l++;
            sum=sum-(en[i]-u);
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
/*


*/
