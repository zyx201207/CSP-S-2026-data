#include<iostream>
#include<vector>
using namespace std;
int s[500005];
vector<int> v[500005],w[500005];
long long a[505][505];
inline long long minn(long long x,long long y){
    return x<y?x:y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(i);
            w[x].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                a[i][j]=1e18;
            }
        }
    }
    for(int i=1;i<=m;i++){
        int sz=v[i].size();
        for(int j=0;j<sz;j++){
            int p=v[i][j];
            for(int k=j+1;k<sz;k++){
                int q=v[i][k];
                a[q][p]=a[p][q]=min(0ll+w[i][k]+w[i][j],a[p][q]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        int sl=v[l].size();
        int sr=v[r].size();
        long long ans=1e18;
        for(int j=0;j<sl;j++){
            int p=v[l][j];
            for(int k=0;k<sr;k++){
                int q=v[r][k];
                //cout<<p<<' '<<q<<' '<<a[p][q]<<'\n';
                ans=min(ans,a[p][q]+w[l][j]+w[r][k]+s[l]+s[r]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//Arsenal was and still is my love.
//North London Forever.
