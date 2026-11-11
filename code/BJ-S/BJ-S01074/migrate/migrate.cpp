#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6,INF=0x3f3f3f3f;
typedef pair<ll,ll> PII;

ll c,T;
ll n,d;
ll a[N];
//vector<PII> mp[N];

vector<PII> b;



ll k,res=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        res=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-3;i++){
            if((a[i+2]-a[i])<=d && (a[i+3]-a[i])>d && (a[i+3]-a[i+1])<=d){
                res++;
            }
        }
        cout<<res<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
