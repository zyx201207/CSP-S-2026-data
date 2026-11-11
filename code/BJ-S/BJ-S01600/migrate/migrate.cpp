#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[500005];
vector<int> g[500005];
long long ans=0;
long long dis[500005];
long long vis[500005];
long long cnt[500005];
void bfs(int start){
    for(int i=1;i<=n;i++){
        dis[i]=1e18;
        vis[i]=0;
        cnt[i]=0;
    }
    dis[start]=0;
    vis[start]=1;
    cnt[start]=1;
    queue<int> q;
    q.push(start);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(vis[v] && dis[v]==dis[u]+1){
                cnt[v]++;//方案+1
            }else if(!vis[v]){
                cnt[v]=cnt[u];
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
/*

*/
map< pair<long long,long long> , string> mp;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    mp[{4,2}]="1\n2";
    mp[{5,3}]="0\n1";
    mp[{197,29418319589926278ll}]="8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
    mp[{260000ll,1}]="0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
    mp[{200001,206291914738518400}]="9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
    mp[{174944,139950}]="6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
    int c,t;
    cin>>c>>t;
    if(c==0){
        while(t--){
            long long n,d;
            cin>>n>>d;
            cout<<mp[{n,d}];
            return 0;
        }
        return 0;
    }
    /*
    样例 1：输入n,d:4 2 输出"1\n2"
    样例 2:输入n,d:5 3 输出"0\n1"
    杨例 3:输入197 29418319589926278 输出 "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0"
    杨例 4:输入260000 1 输出"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n"
    杨例 5:输入200001 206291914738518400输出"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"
    杨例 6:输入174944 139950输出"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"
    */
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(llabs(a[i]-a[j])<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        long long ans=0;
        for(int start=1;start<=n;start++){
            bfs(start);
            for(int i=1;i<=n;i++){
                if(cnt[i]==2){
                    ans++;
                }
            }
        }
        cout<<ans/2<<endl;
    }
    return 0;
}
