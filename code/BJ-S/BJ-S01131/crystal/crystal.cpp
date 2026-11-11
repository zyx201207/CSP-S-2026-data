#include<bits/stdc++.h>
#define maxn 500005
#define int long long
using namespace std;
int n,m;
int a[maxn],d[maxn];
int ans;
//d[1]=a[2]-a[1]; 1~n-1
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>5000){
        //(x+1)*x/2<=m
        int x=1,dd=a[2]-a[1];
        while((x+dd)*x/2<=m) x++;
        cout<<x;
        return 0;
    }
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        int cnt=0,sum=1;
        if(m>d[i]){
            for(int j=1;;j++){
                cnt+=d[j]*j;
                if(cnt>m) break;
                else sum++;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
