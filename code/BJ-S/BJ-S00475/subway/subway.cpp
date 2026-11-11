#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long c,n,m,d,q,a[N],cnt,x,y,sum,res,b[N];
bool r,l;
vector<int> s[N];
vector<int> g[N];
void dfs(int u){
    l=false;
    r=false;
    if(u==y){
        //res=min(res,cnt);
        return;
    }
    int p=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]==y){
                r=true;
            }
            if(s[i][j]==u){
                l=true;
            }
        }
        if(r==true&&l==true){
            cnt+=g[u][i-1];
            cnt+=g[y][i-1];
            p++;
            break;
        }
        r=false;
        l=false;
    }
    /*
    if(p==0){
        int q=0,h=0;
        for(int i=1;i<=n;i++){
            q=0;
            for(int j=1;j<=n;j++){
                if(s[i][j]==u){
                    q++;
                }
                if(q!=0&&g[s[i][j]].size()>1){
                    for(int ii=0;ii<g[s[i][j]].size();ii++){
                        if(g[s[i][j]][ii]!=0){
                            cnt+=g[s[i][j]][ii];
                        }
                    }
                    dfs(s[i][j]);
                }
            }
        }
    }
    return ;
    */
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int xx,t;
            cin>>xx>>t;
            s[i].push_back(xx);
            g[xx].push_back(t);
        }
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(int j=0;j<s[i].size();j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for(int i=1;i<=m;i++){
        cout<<i<<": ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    //*/
    for(int i=1;i<=q;i++){
        cnt=0;
        cin>>x>>y;
        sum=10000000000;
        res=sum;
        l=false;
        r=false;
        cnt+=a[x];
        cnt+=a[y];
        dfs(x);
        //sum=min(sum,res);
        cout<<cnt<<endl;
    }
    return 0;
}

