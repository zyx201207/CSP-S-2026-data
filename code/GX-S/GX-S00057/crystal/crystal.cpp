#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005],a1[500005];
signed main(){
    freopen("crystal.in",'r',stdin);
    freopen("crystal.out",'w',stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,mn;
    cin>>n>>m;
    mn=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a1[i]=a[i];//beifen
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(m==0) break;
            if(a[j]<a[i]){
                while(a[j]<a[i]){
                    if(m==0) break;
                    m--;
                    a[j]++;
                }
            }
        }
        for(int j=i;j>=1;j--){
            if(a[j]==a[i]) ans++;
        }
        b[i]=ans;
        ans=0;
        m=mn;
        for(int j=1;j<=n;j++){
            a[j]=a1[j];
        }
    }
    int maxn=-1e18;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,b[i]);
    }
    cout<<maxn;
}//zhetaishifenle
//CCF,please give me some points!Thank you very much.
