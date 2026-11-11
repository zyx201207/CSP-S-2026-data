#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=INT_MAX;
int c,n,m,d,q;
int w[500005];
int tc[500005][502],ex[502][502];
int k,a,t;
int x,y;
vector<int>sta[502];
vector<int>line[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    //cout<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            tc[a][i]=t;
            sta[i].push_back(a);
            line[a].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                ex[i][j]=INF;
            }
            else{
                ex[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(line[i].size()>1){
            for(int r=1;r<line[i].size();r++){
                for(int l=0;l<r;l++){
                    int e=line[i][r],f=line[i][l];
                    ex[e][f]=min(ex[e][f],tc[i][e]+tc[i][f]);
                    ex[f][e]=min(ex[f][e],tc[i][e]+tc[i][f]);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ex[i][j]>ex[i][k]+ex[k][j]){
                    ex[i][j]=ex[i][k]+ex[k][j];
                }
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ex[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<line[i].size();j++){
            cout<<line[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<w[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<tc[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        int ans=INF;
        for(int e=0;e<line[x].size();e++){
            for(int f=0;f<line[y].size();f++){
                //cout<<line[x][e]<<" "<<line[y][f]<<":"<<endl;
                //cout<<tc[x][e]<<" "<<tc[y][f]<<" "<<ex[e][f]<<endl;
                ans=min(ans,tc[x][line[x][e]]+tc[y][line[y][f]]+ex[line[x][e]][line[y][f]]);
                //cout<<ans<<endl;
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
