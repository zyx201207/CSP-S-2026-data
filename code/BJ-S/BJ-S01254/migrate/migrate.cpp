#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define x first
#define y second
#define ls p<<1
#define rs p<<1|1
#define pb push_back

const int N=2e6+10,M=1e18+10;
int n,m,c,t,q,x[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    //
    cin>>c>>t;
    while(t--){
        cin>>n>>q;
        if(n>=2e5){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            cin>>x[i];

        }
        int ans=0;
        for(int j=1;j<=n;j++){
            priority_queue<PII> h;
            vector<int> st(n+1),d(n+1,M),res(n+1);
            h.push({0,j});
            d[j]=0;
            while(h.size()){
                auto p=h.top();
                h.pop();
                int u=p.y,s=p.x;
                //cout<<u<<" "<<-s<<endl;
                res[u]++;
                if(st[u]&&s!=d[u])continue;

                for(int i=u+1;x[i]-x[u]<=q&&i<=n;i++){
                    if(d[i]>d[u]+1){
                        d[i]=d[u]+1;
                        //st[i]=0;
                        h.push({-(d[u]+1),i});
                    }
                    else if(d[i]==d[u]+1){
                        d[i]=d[u]+1;
                        h.push({-(d[u]+1),i});
                    }

                }
            }
            for(int i=1;i<=n;i++){
                if(res[i]==2) ans++;
            }
            //cout<<endl;
        }
        cout<<ans<<endl;


    }

}
