#include<bits/stdc++.h>
#define fin cin
#define fout cout
#define ll long long
using namespace std;
ll dist[505][505],c,d,q,n,m,ls1,ls2,ls3,st[500005];
unordered_map<int,vector<pair<ll,ll>>> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    fin>>c>>n>>m>>d>>q;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        fin>>st[i];
    }for(int i=1;i<=n;i++){
        fin>>ls1;
        dist[i][i]=0;
        for(int j=0;j<ls1;j++){
            fin>>ls2>>ls3;
            for(pair<int,int> k:mp[ls2]){
                dist[k.first][i]=k.second+ls3;
                dist[i][k.first]=k.second+ls3;
            }mp[ls2].push_back({i,ls3});
        }
    }for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }for(int i=1;i<=q;i++){
        fin>>ls1>>ls2;ls3=1e15;if(ls1>ls2) swap(ls2,ls1);
        for(pair<int,int> j:mp[ls1]){
            for(pair<int,int> k:mp[ls2]){

                ls3=min(ls3,dist[j.first][k.first]+j.second+k.second);
            }
        }fout<<ls3+st[ls1]+st[ls2]<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
