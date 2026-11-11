#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5050,M=5e5+50;
int n,m,a[M];
bool fl=1;
int diff,cnt=0,maxx=0;
int sum[N][N];
void tfo(){
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            cout<<sum[j][i]<<" ";
        }
        cout<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            diff=a[2]-a[1];
        }else if(i>2){
            if(a[i]-a[i-1]!=diff){
                fl=0;
            }
        }
    }
    sort(a+1,a+n+1);
    if(fl){
        cnt=1;
        for(int i=1;i<=n-1;i++){
            if(m>=i*diff){
                m-=i*diff;
                cnt++;
            }else{
                break;
            }
        }
        cout<<cnt<<'\n';
    }else{
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                sum[i][j]=abs(a[i]-a[j]);
            }
        }
        for(int i=n;i>=1;i--){
            int ssum=0;
            cnt=1;
            for(int j=i-1;j>=1;j--){
                //cout<<i<<" "<<j<<" "<<cnt<<'\n';
                if(ssum+sum[j][i]<=m){
                    ssum+=sum[j][i];
                    cnt++;
                }else{
                    break;
                }
            }
            maxx=max(maxx,cnt);
        }
        cout<<maxx<<'\n';
        //tfo();
    }
    return 0;
}
