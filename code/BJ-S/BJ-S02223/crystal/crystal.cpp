#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],chaf[N],maxm=-1e18;
int sie(int x)
{
    int cx[x],ans=1,tmp=m,sum=0;
    for(int i=x-1;i>=1;i--){
        sum+=chaf[i];
        if(tmp-sum>=0){
            tmp-=sum;
            ans++;
        }
        else break;
    }
    //for(int i=1;i<x;i++) cout<<cx[i]<<' ';
    //cout<<endl<<ans<<' '<<endl;
    return ans;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        chaf[i]=a[i+1]-a[i];
    }
    int mid=n/2;
    if(n>5000){
        if(a[1]==1&&a[2]==2){
            int ans;
            for(int i=1;i<=n;i++){
                int ag=i-1;
                if(m-ag>=0){
                    m-=ag;
                    ans=i;
                }
            }
            cout<<ans;
            return 0;
        }
        else if(a[2]-a[1]==a[3]-a[2]){
            int gc=a[2]-a[1];
            int ans;
            for(int i=1;i<=n;i++){
                int ag=gc*(i-1);
                if(m-ag>=0){
                    m-=ag;
                    ans=i;
                }
            }
            cout<<ans;
            return 0;
        }
    }
    while(1){
        int cnt=sie(mid),rp=sie(mid+1),pj=sie(mid-1);
        if(rp>cnt) mid++;
        else if(pj>cnt) mid--;
        else{
            maxm=cnt;
            break;
        }
    }
    cout<<maxm;
    return 0;
}
