#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[500005],cnt;
int jl[500005];
set<int>st;
map<int,int>mp;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(a[i]!=a[i-1]){
            jl[a[i]]=i-1;
        }
    }
    if(n>5){
        for(int i=1;i<=m;i++){
            cout<<mp[i]+jl[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(st.count(a[j])){
                st.clear();
            }
            st.insert(a[j]);
        }
        for(auto it=st.begin();it!=st.end();it++){
            ans[*it]++;
        }
        st.clear();
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
