#define ll long long

#include <bits/stdc++.h>
using namespace std;

const ll MAXN=1e6*2+7;

ll c,t,n,d;
ll a[MAXN],dis[MAXN];

ll ans;

bool ta[MAXN];

struct node{
    ll to;
    ll w;
};

vector<node> g[MAXN];

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;

    /*
    if(c==0){
        while(t--){
            if(t==4){
                cin>>n>>d;
                cout<<n<<" "<<d<<endl;
                for(ll i=1;i<=n;++i){
                    cin>>a[i];
                    cout<<a[i]<<" ";
                }
                //cout<<a[1]<<" "<<a[2]<<" "<<a[3];
            }else{
                cin>>n>>d;
                for(ll i=1;i<=n;++i){
                    cin>>a[i];
                }
            }
        }
        return 0;
    }

    */

    //Task 11-12 c!=0
    if(c==11||c==12){

        while(t--){
            cin>>n>>d;
            for(ll i=1;i<=n;++i){
                cin>>a[i];
            }
            ll td=a[2]-a[1];
            if(td>=d){
                cout<<0<<endl;
                continue;
            }else{
                ll tk=d/td;
                if(tk==2){
                    cout<<n-3<<endl;
                }else if(tk>2){
                    if(n>=2*tk-1){
                        cout<<n-(2*tk-1)<<endl;
                    }else{
                        cout<<0<<endl;
                    }
                }
            }
        }

        return 0;

    }else if(c==13||c==14){

        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;++i){
                cin>>a[i];
                dis[i]=a[i]-a[i-1];
            }


        }

        return 0;

    }else{
    //Task 1-10
        while(t--){
            cin>>n>>d;
            for(ll i=1;i<=n;++i){
                cin>>a[i];
                dis[i]=a[i]-a[i-1];
            }
            //建图
            for(ll i=1;i<=n;++i){
                ll sumi=0;
                for(ll j=i+1;j<=n&&sumi+dis[j]<=d;++j){
                    sumi+=dis[j];
                    node v;
                    v.to=j;v.w=1;
                    g[i].push_back(v);
                    //cout<<i<<" "<<j<<endl;
                }
            }
            //建边
            for(ll i=1;i<=n;++i){

            }

        }
        return 0;
    }

    return 0;
}
