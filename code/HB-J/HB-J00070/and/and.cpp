#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[35],lost[200005];
bool bit[200005][35],lostbit[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,maxbit=0,losts=0,tlost=0,ans=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t=a[i],j=1;
        while(t){
            bit[i][j]=(bool)(t%2);
            sum[j]+=bit[i][j];
            t/=2;j++;
        }
        maxbit=max(maxbit,j);
    }
    for(int j=maxbit;j>=1;j--){
        if(n-losts==m) break;
        tlost=0;
        if(sum[j]<m) continue;
        for(int i=1;i<=n;i++){
            if(lost[i]) continue;
            if(!bit[i][j]){
                lost[i]=j;
                tlost++;
                sum[j]--;
            }
        }
        if(n-losts-tlost>=m) losts+=tlost;
        else{
            for(int i=1;i<=n;i++){
                if(lost[i]==j) lost[i]=0;
            }
            continue;
        }
    }
    for(int i=1;i<=n;i++){
        if(lost[i]) continue;
        if(ans==-1) ans=a[i];
        else ans&=a[i];
    }
    cout<<ans;
    return 0;
}
