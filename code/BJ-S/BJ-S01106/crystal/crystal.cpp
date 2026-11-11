#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,c[N],a[N][2],top=1,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+n+1);
    a[1][0]=c[1];
    a[1][1]=1;
    for(int i=2;i<=n;i++){
        if(c[i]!=a[top][0]){
            top++;
            a[top][0]=c[i];
            a[top][1]=1;
        }else a[top][1]++;
    }
    for(int i=1;i<=top;i++){
        ll num=a[i][1],m1=m;
        for(int j=i-1;j>=1;j--){
            if(m1<a[i][0]-a[j][0])break;
            int t=min(a[j][1],m1/(a[i][0]-a[j][0]));
            num+=t;
            m1-=t*(a[i][0]-a[j][0]);
        }
        ans=max(ans,num);
    }
    cout<<ans;
    return 0;
}