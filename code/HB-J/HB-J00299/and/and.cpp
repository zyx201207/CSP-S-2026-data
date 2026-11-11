#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn=2e5+50;
int a[maxn];
int n,m;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    //cout<<endl;
    int ans=0;
    for(int i=1;i<=n-m;i++){
        int res=a[i];
        //cout<<a[i]<<" ";
        for(int j=i+1;j<i+m;j++){
            //cout<<a[j]<<" ";
            res&=a[j];
        }
       //cout<<res<<endl;
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}