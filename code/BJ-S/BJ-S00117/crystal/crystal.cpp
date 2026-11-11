#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e5+5;
int n,m,llll,a[N],ans=-1,zans=1;
vector<int>v;

int jisuan(int i){
    int he=0;
    for(int j=0;j<i;j++){
        he+=abs(v[i]-v[j]);
    }
    return he;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>llll;
        v.push_back(llll);
    }
    sort(v.begin(),v.end());
    a[0]=v[0];
    for(int i=1;i<n;i++){
        int p=jisuan(i);
        if(p<=m){
            ans=max(ans,p);
            if(ans==p){
                zans=i+1;
            }
        }
    }
    cout<<zans;
}
