#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=500005,MAXM=300005;
int ans[MAXN];
int a[MAXN],last[MAXN];
bitset<MAXM> have;
bool flag=true;
int n,m;
void solve(int l){
    have=0;
    vector<int> q;
    memset(last,0,sizeof(last));
    q.resize(n+5,0);
    q.push_back(0);
    if(flag){
        for(int i=l;i<=n;i++)
            q.push_back(a[i]);
    }else
        for(int i=l;i<=n;i++){
            if(last[a[i]]){
                for(int j=last[a[i]]+1;j<q.size();j++)
                    q[j]=0;
            }
            last[a[i]]=q.size();
            q.push_back(a[i]);
        }
    for(int &x:q)
        have[x]=true;
    for(int i=1;i<=m;i++)
        ans[i]+=have[i];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(!(a[i]>=a[i-1]))flag=false;
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)solve(i);
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}