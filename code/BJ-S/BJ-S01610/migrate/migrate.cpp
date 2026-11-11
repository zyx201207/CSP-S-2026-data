#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=2e6+5;

int cc,t,n;
ll d,a[maxn],ans,dd;
int nx[maxn],f[5005][5005];
bool vs[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cc>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i],nx[i]=0;
        for(int i=1;i<=n;i++)nx[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
        dd=a[2]-a[1];
        for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=dd)dd=-1e18;
        if(n>=2&&dd>0){
            ll kk=d/dd;
            for(int i=1;i<=n;i++){
                if(kk>1&&i+kk+kk-1<=n)ans++;
            }
            cout<<ans<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)f[i][j]=0;
        for(int i=n;i>=1;i--){
            for(int j=i+1;j<=n;j++){
                for(int k=i;k<=j;k++)vs[k]=0;
                int p=nx[i],ls=i;
                //cout<<i<<',';
                vs[i]=1;
                while(p!=ls&&p<j)vs[p]=1,f[i][j]++,ls=p,p=nx[p];
                if(p>=j){
                    f[i][j]++,vs[j]=1;
                    int s=0;
                    for(int k=i;k<=j;k++)if(!vs[k]&&f[i][k]+f[k][j]==f[i][j])s+=2;
                    if(s==2)ans++;//,cout<<i<<','<<j<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
