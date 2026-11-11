#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII piar<int,int>
#define x first
#define y second
#define ls p<<1
#define rs p<<1|1
#define pb push_back

const int N=5e5+10,Z=1e18,M=3e5+10;

int n,t,a[N],st[N],b[N],m,ans[N];
string s;

void qweasd(){
    cin>>n>>m;
    vector<vector<int> > z(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        int u=a[i];
        if(b[u]==0){
            b[u]=i;
            z[i].pb(u);
            //z[i]=z[i+1];
            for(int j=0;j<z[i+1].size();j++){
                z[i].pb(z[i+1][j]);
            }
        }
        else{
            st[u]=i;

            //z[i]=z[b[u]+1];
            for(int j=0;j<z[b[u]].size();j++){
                z[i].pb(z[b[u]][j]);
            }
        }
        /*for(int j=0;j<z[i].size();j++){
            cout<<z[i][j]<<" ";
        }
        cout<<endl;*/

    }
    for(int j=1;j<=n;j++){
        for(int i=0;i<z[j].size();i++){
            ans[z[j][i]]++;
        }
    }
    for(int i=1;i<=m;i++) {cout<<ans[i];if(m!=i){cout<<" ";}};
    cout<<endl;
    //\diff card6.out card6.ans
}

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    t=1;

    while(t--){

        qweasd();

    }
    return 0;
}
