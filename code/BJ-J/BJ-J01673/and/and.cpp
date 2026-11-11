#include<bits/stdc++.h>
#define N 300050
#define ll long long
#define qck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll a[N][40];
ll n,m,x;
ll maxpos,ans;
bool fail[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    qck;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        ll pos=0;
        while(x){
            a[i][++pos]=x%2;
            x/=2;
        }
        maxpos=max(maxpos,pos);
    }
    for(int i=maxpos;i>=1;i--){
        int use=0;
        for(int j=1;j<=n;j++){
            if(!fail[j]&&a[j][i]==1) use++;
        }
        // cout<<use<<"\n";
        if(use<m) continue;
        for(int j=1;j<=n;j++){
            if(!fail[j]&&a[j][i]==0) fail[j]=1;
        }
        ans+=(1<<(i-1));
    }
    cout<<ans<<"\n";
    return 0;
}