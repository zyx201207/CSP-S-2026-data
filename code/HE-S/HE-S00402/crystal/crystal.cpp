#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long cha[500005];
long long cs[500005];
int ans=0;
int tem=0;
long long cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cha[1]=0;
    for(int i=2;i<=n;i++) cha[i]=a[i]-a[i-1];
    cs[1]=cha[1];
    for(int i=2;i<=n;i++) cs[i]=cs[i-1]+cha[i];
    /*for(int o=1;o<=n;o++) cout<<cha[o]<<" ";
    cout<<endl;
    for(int o=1;o<=n;o++) cout<<cs[o]<<" ";
    cout<<endl;*/
    for(int i=1;i<=n;i++){
        cnt=0;
        tem=1;
        //cout<<i<<"****"<<endl;
        for(int j=i-1;j>=1;--j){
            if(cnt+cs[i]-cs[j]<=m){
                cnt=cnt+cs[i]-cs[j];
                tem++;
                //cout<<i<<" "<<j<<" "<<cnt<<" "<<tem<<endl;
                continue;
            }else break;
        }
        ans=max(ans,tem);
    }
    cout<<ans;
    return 0;
}
