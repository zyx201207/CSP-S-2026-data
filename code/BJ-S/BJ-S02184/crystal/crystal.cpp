#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10,maxm=1e8+5;
int a[maxn];
int w[maxn],v[maxn],dp[maxm];
map<int,int> cnt;
int n,m;
int ans=0;
void solve(){
    sort(a+1,a+n+1);//greater
    for(int i=1;i<=n;i++){
        if(a[i-1]==a[i]) continue;
        //int i=5;
        int _start=1,_end=i-1;
        //printf("start=%d,end=%d\n",_start,_end);
        for(int j=i-1;j>=1;j--){
            w[j]=abs(a[i]-a[j]);v[j]=1;dp[j]=0;
        }
        //cout<<"w:";for(int j=_start;j<=_end;j++) cout<<w[j]<<" ";cout<<"\n";
        //cout<<"v:";for(int j=_start;j<=_end;j++) cout<<v[j]<<" ";cout<<"\n";

        for(int j=_start;j<=_end;j++){
            for(int k=m;k>=w[i];k--){
                dp[k]=max(dp[k],dp[k-w[j]]+v[j]);
            }
        }int tans=0;
        for(int j=1;j<=m;j++){
            tans=max(tans,dp[j]);
        }
        //cout<<a[i]<<":"<<tans<<"+"<<cnt[a[i]]<<"\n";

        ans=max(ans,tans+cnt[a[i]]);
        //cout<<"dp:";for(int j=1;j<=m;j++) cout<<dp[j]<<" ";cout<<"\n";
    }

    cout<<ans;
}
int diff=-1;
signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    bool specialPoint=true;//sameDiff

    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(i!=1){
            int d=abs(a[i]-a[i-1]);
            if(diff==-1) diff=d;
            if(diff!=-1&&diff!=d) specialPoint=false;
        }
    }

    if(specialPoint){
        //set ans = p, start = a[1]
        //|delet|so a[x] = start + diff*x
        //need(m) = 0*diff + 1*diff + ... + (p-1)*diff
        //        = (0+1+2+3+...+p-1)*diff
        //        = (0+p-1)*p/2*diff
        int p=0;
        while(!((0+(++p)-1)*p/2*diff>m)&&p-1<=n);//p-1 must less than n
        cout<<p-1;
    }


    return 0;
}



/*

5 5
1 2 4 8 9

*/
