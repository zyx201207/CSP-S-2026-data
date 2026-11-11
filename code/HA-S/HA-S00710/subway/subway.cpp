#include<bits/stdc++.h>
using namespace std;
int c,d,m,n,q;
const int MAXM=500010;
const int MAXN=510;
int w[MAXM],k[MAXN],a[MAXN][MAXN],t[MAXN][MAXN],x[100001],y[100001];vector<int> xl[100001], yl[100001];int vis[MAXN];
map<pair<int,int>,vector<int> > trans;
vector<int> ansx;
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
void dfs(int nowl,int nowid,int time,int ansl,int ansid){
    if(nowid==ansid || nowl==ansl){
        //cout<<"app:"<<ansl<<" "<<time+t[ansl][ansid]+w[ansid]<<endl;
        ansx.push_back(time+t[ansl][ansid]+w[ansid]);
        return;
    }
    vis[nowl]=1;
    for(int i=1;i<=n;i++){
        vector<int> lines=trans[make_pair(nowl,i)];
        if(!lines.empty() && vis[i]==0 ){
//            if(lines.size()!=1) exit(114514);
//            for(int stat:lines){
            if(1){
                int stat=lines[0];
                // fromline -> toline

                dfs(i,stat,time+t[i][stat]+t[nowl][stat],ansl,ansid);
                vis[i]=0;
            }
        }

    }
    vis[nowl]=0;
    return;
}
int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        for(int j=1;j<=n;j++){
            for(int g=1;g<=k[j];g++){
                if(a[j][g]==x[i]){
                    xl[i].push_back(j);
                }
                if(a[j][g]==y[i]){
                    yl[i].push_back(j);
                }
            }
        }
    }

    for (int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                vector<int> ans;
                for(int l=1;l<=k[i];l++)
                for(int r=1;r<=k[j];r++){
                    if(a[i][l]==a[j][r]){ans.push_back(a[i][l]);break;}
                }
                trans[make_pair(i,j)]=ans;
            }
    }
    for(int i=1;i<=q;i++){
        ansx=vector<int>();
        for(int j:xl[i]){for(int k:yl[i]){

                //cout<<j<<" "<<k<<endl;
            dfs(j,x[i],w[x[i]]+t[j][x[i]],k,y[i]);
        if(j==k){
        		break;
        	}
        }}
        int minn=0x3f3f3f3f;
        for(int ans:ansx){
            minn=min(ans,minn);
        }
        cout<<minn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
