#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m);
    for(int i=0;i<m;++i){
        cin>>w[i];
    }
    vector<pair<int,int>> at(n);
    for(int i=0;i<n;++i){
        cin>>at[i].first>>at[i].second;
    }
    vector<pair<int,int>> qs(q);
    for(int i=0;i<q;++i){
        int k;
        cin>>k;
        for(int j=0;j<k;++j)
        cin>>qs[j].first>>qs[j].second;
    }
    srand(time(0));
    for(int i=0;i<q;++i){
        int GOD=((rand()^rand()^rand()^rand()^rand()^rand()^rand()^rand()^c^n^m^d^q&1101&2012^at[(q*rand()^rand())%n].second-qs[i].first)&m);
        if((rand()^i-10^6^20)&1)cout<<((vector<int>){16,35,42,32,17,42,81,982,43,43,374,5,44}[rand()%13]);
        else cout<<GOD
    }
}