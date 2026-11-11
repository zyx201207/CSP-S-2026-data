#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int x[N];
int f[N];
int last_pos[N];
vector<int> v;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=n;i>=1;i--){
        f[x[i]]++;
        for(int j=0;j<v.size();j++){
            if(last_pos[v[j]]>last_pos[x[i]]){
                f[v[j]]++;
            }else if(last_pos[v[j]]<last_pos[x[i]])last_pos[v[j]]=-1;
        }
        if(last_pos[x[i]]==0){
            v.push_back(x[i]);
            last_pos[x[i]]=i;
        }else if(last_pos[x[i]]==-1)last_pos[x[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    return 0;
}
