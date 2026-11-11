#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

typedef long long ll;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> ene(n);
    bool specialA=true;
    for(int i=0;i<n;i++){
        cin>>ene[i];
        specialA=specialA&&(i==0||(ene[i]==ene[i-1]));
    }
    if(specialA){
        cout<<n;
        return 0;
    }
    ll mx=0;
    for(int i=0;i<n;i++){
        ll crystals=0;
        int bl=m;
        int tgt=ene[i];
        for(int j=0;j<n && bl>=0;j++){
            int dt=tgt-ene[j];
            if(dt>=0 && bl>=dt){
                bl-=dt;
                crystals++;
                //printf("dt %d j %d ene[j] %d tgt %d bl %d\n",dt,j,ene[j],tgt,bl);
            }
        }
        if(mx<crystals){
            mx=crystals;
        }
    }
    cout<<mx;
    return 0;
}
