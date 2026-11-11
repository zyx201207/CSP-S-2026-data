#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int ans_max=0;
    for(int i=n;i>1;i--){
        int cha=0,ans=1;
        for(int j=i-1;j>=1;j--){
            cha+=a[i]-a[j];
            if(cha<=m){
                ans++;
            }else{
                break;
            }
        }
        ans_max=max(ans_max,ans);
    }
    cout<<ans_max;
    return 0;
}
