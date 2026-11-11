#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c;
int t;
int n;
long long d;
long long a[N];
int pi[N];
int zf[5000][5000];
int f[5000][5000];
long long ans;
void sol1(){
    long long b=d/(a[2]-a[1]);
    if(b<=1||b*2-1>n){
        ans=0;
    }
    else ans=n-(b*2-1);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            sol1();
        }
        else {
            for(int i=1;i<=n;i++){
                pi[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
            }
            for(int i=1;i<=n;i++)f[i][i]=1;
            ans=0;
            for(int l=2;l<=n;l++){
                for(int i=l;i<=n;i++){
                    int j=i-l+1;
                    //if(pi[i]<=j)continue;
                    zf[i][j]=1e6+5;
                    f[i][j]=0;
                    for(int g=max(pi[i],j);g<=i-1;g++){
                        if(zf[g][j]+1<zf[i][j]){
                            f[i][j]=f[g][j];
                            zf[i][j]=zf[g][j]+1;
                            if(f[i][j]>2)break;
                        }
                        else if(zf[g][j]+1>zf[i][j])continue;
                        else f[i][j]+=f[g][j];
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<i;j++){
                    if(f[i][j]==2)ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
