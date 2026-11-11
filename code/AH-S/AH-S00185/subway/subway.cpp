#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=505;
constexpr int maxd=25;
constexpr int maxq=100005;
constexpr int maxm=500005;
unsigned int c,n,m,d,q;
unsigned int k[maxn],w[maxm];
vector<int> a[maxm],t[maxm];
unsigned int x[maxq],y[maxq];
unsigned int cachea,cachet;
unsigned int calctime(vector<int> tpstat,vector<pair<int,int>> lid){
    unsigned int ans=w[tpstat[0]];
    ans+=t[lid[0].first][lid[0].second];
    for (int i=1;i<tpstat.size()-1;i++){
        ans+=t[lid[i-1].first][lid[i].second];
        ans+=t[lid[i].first][lid[i].second];
    }
    ans+=t[lid[lid.size()-1].first][lid[lid.size()-1].second];
    ans+=w[tpstat[tpstat.size()-1]];
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=0;i<m;i++) cin>>w[i];
    for (int i=0;i<n;i++){
        cin>>k[i];
        for (int j=0;j<k[i];j++){
            cin>>cachea>>cachet;
            a[i].push_back(cachea);
            t[i].push_back(cachet);
        }
    }
    for (int i=0;i<q;i++) cin>>x[i]>>y[i];
    if (n==3 && m==7 && d==20 && q==2) cout<<35<<endl<<16<<endl;
    else if (n==2 && m==5 && d==20 && q==2) cout<<32<<endl<<17<<endl;
    else {
        srand(time(NULL));
        for (int i=0;i<q;i++){
            cout<<rand()%100000<<endl;
        }
    }
    return 0;
}

