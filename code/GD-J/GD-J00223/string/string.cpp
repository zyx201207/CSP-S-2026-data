#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
#define ls (p<<1)
#define rs (ls|1)
const int N=2e6+10;
ll a[N];
ll sum;
int n;
char c[N];
stack<pair<int,char>> q1,q2;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        sum+=a[i];
    }
    ll now=0,las=0;
    for(int i=1;i<=n;i++){
        // las=i;
        // now+=a[i];
        if(now+a[i]<=sum/2){
            las=i+1;
            // q1.push({a[i],c[i]});
        }
        else{
            if(now==sum/2){
                if(sum&1)a[i]--;
                las=i;
                break;
            }
            else{
                las=i;
                q1.push({sum/2-now,c[i]});
                a[i]-=(sum/2-now);
                if(sum&1)a[i]--;
                break;
            }
        }
        now+=a[i];
    }
    for(int i=las-1;i>=1;i--){
        q1.push({a[i],c[i]});
    }
    for(int i=las;i<=n;i++){
        q2.push({a[i],c[i]});
    }  
    ll ans=0;
    while(q1.size()&&q2.size()){
        int c1=q1.top().first;
        int c2=q2.top().first;
        char p1=q1.top().second;
        char p2=q2.top().second;
        // cout<<c1<<' '<<c2<<' '<<p1<<' '<<p2<<"\n";
        q1.pop();q2.pop();
        if(c1==c2){
            if(p1!=p2)ans+=c2;
            continue;
        }
        if(c1>c2){
            if(p1!=p2)ans+=c2;
            q1.push({c1-c2,p1});
        }
        else{
            if(p1!=p2)ans+=c1;
            q2.push({c2-c1,p2});
        }
    }
    cout<<ans;
}