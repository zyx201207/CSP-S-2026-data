#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,n,p[N],lst[N],dis[N],s[N];
ll d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            p[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
        }
        int ans=0;
        if(n>5000){
            d/=(a[2]-a[1]);
            if(d>1){
                if(2ll*d-1<=n-1) ans=n-(2ll*d-1);
            }
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            s[i-1]=0,s[i]=1,dis[i]=0,lst[0]=i;
            for(int j=i+1;j<=n;j++){
                if(p[j]==j) break;
                dis[j]=dis[max(p[j],i)]+1;
                int f=min(s[lst[dis[j]-1]]-s[max(p[j],i)-1],3);
                s[j]=s[j-1]+f;
                if(f==2) ans++;
                lst[dis[j]]=j;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}