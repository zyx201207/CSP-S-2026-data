#include<bits/stdc++.h>
#define N 200010
#define int long long
using namespace std;

int n,m;
int a[N],pw[32];
bool flag[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mx_w=__lg(a[n]);
    pw[0]=1;
    for(int i=1;i<=30;i++){
        pw[i]=pw[i-1]*2;
    }
    int ans=0;
    for(int i=mx_w;i>=0;i--){
        int cnt=0;
        bool temp[N]={};
        for(int j=1;j<=n;j++){
            if(flag[j]) continue;
            if((a[j]/pw[i])%2==1){
                temp[j]=true;
                cnt++;
            }
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(temp[j]==false) flag[j]=true;
            }
            ans+=pw[i];
        }
    }
    cout<<ans;
    return 0;
}