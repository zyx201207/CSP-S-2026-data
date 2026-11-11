#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+5;

int n,m;

int clac(vector<int> a,int pre){
    vector<int> v[50];
    for(int i=0;i<a.size();i++){
        for(int j=0;j<=30;j++){
            if((a[i]>>j)&1) v[j].push_back(a[i]);
        }
    }
    for(int i=pre-1;i>=0;i--){
        if(v[i].size()>=m){
            if(pre!=31){
                for(int j=1;j<v[i].size();j++) v[i][j]^=1<<pre;
            }
            int res=v[i][0];
            for(int j=1;j<v[i].size();j++) res&=v[i][j];

            if(v[i].size()==m) return res;
            else return (1<<i)+clac(v[i],i);
            break;
        }
    }
    return 0;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    vector<int> in;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        in.push_back(x);
    }
    cout<<clac(in,31);
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/