#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

struct node{
    int to,w;

    bool operator <(const node&T)const{
        return w>T.w;
    }
};

struct line{
    int k;
    map <int,int> mp;
};
line a[505];

vector <int> cross[500005];
vector <node> e[500005];
int w[500005];
int vis[505];
int lst[505];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,_; cin>>c>>n>>m>>d>>_;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>a[i].k;

        for(int j=1;j<=a[i].k;j++){
            int x,y; cin>>x>>y;
            a[i].mp[x]=y;
            cross[x].push_back(i);
        }
    }

    for(int i=1;i<=m;i++){
        //cout<<"i: "<<i<<endl;
        for(int j=0;j<cross[i].size();j++){
            //cout<<"j: "<<j<<endl;
            for(int k=0;k<j;k++){
                //cout<<"k: "<<k<<endl;
                int jj,kk; jj=cross[i][j]; kk=cross[i][k];
                e[jj].push_back({kk,a[jj].mp[i]+a[kk].mp[i]});
                e[kk].push_back({jj,a[jj].mp[i]+a[kk].mp[i]});
                //cout<<jj<<" "<<kk<<" "<<a[jj].mp[i]+a[kk].mp[i]<<endl;
            }
        }
    }

    //cout<<"out"<<endl;
    while(_--){
        //cout<<_<<endl;
        int l,r; cin>>l>>r;
        //cout<<"lr:"<<endl;
        //cout<<l<<" "<<r<<": ";

        priority_queue <node> q;
        memset(vis,0x3f3f3f3f,sizeof vis);
        for(auto T:cross[l]){
            q.push({T,a[T].mp[l]});
            vis[T]=a[T].mp[l];
        }

        //cout<<"ttt"<<endl;
        for(auto T:cross[r]){
            lst[T]=1;
        }

        int ans; ans=w[l]+w[r];
        while(!q.empty()){
            node x; x=q.top(); q.pop();
            //cout<<q.size()<<" "<<x.to<<" "<<x.w<<endl;
            if(x.to==-1){
                ans+=x.w;
                break;
            }

            if(lst[x.to]){
                q.push({-1,x.w+a[x.to].mp[r]});
                continue;
            }

            for(auto to:e[x.to]){
                if(vis[to.to]>x.w+to.w){
                    vis[to.to]=x.w+to.w;
                    q.push({to.to,x.w+to.w});
                }
            }
        }

        for(auto T:cross[r]){
            lst[T]=0;
        }

        cout<<ans<<"\n";
    }
    return 0;
}
/*
Est Score:
[60-100]

subway6 run for 1.3s
is it my problem or is it device's problem
this room's device is slow on windows
idk abt noilinux tho

luogu 635361
*/
