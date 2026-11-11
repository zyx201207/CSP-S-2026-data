#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct seg{
    long long cnt;
    char val;
}inp[MAXN];
vector<seg> sol1,sol2;
int n;
long long l=0,rad;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>inp[i].cnt;
        cin >>inp[i].val;
        l+=inp[i].cnt;
    }
    long long nowl=0;
    rad=l/2;
    if(l%2==1) rad++;
    bool isleft=1;
    for(int i=1;i<=n;i++){
        if(nowl<=rad&&nowl+inp[i].cnt>=rad){
            sol1.push_back({rad-nowl,inp[i].val});
            long long r=nowl+inp[i].cnt-rad;
            if(l%2==1) r++;
            sol2.push_back({r,inp[i].val});
            nowl+=inp[i].cnt;
            if(l%2==1) nowl++;
            isleft=false;
        }else{
            if(isleft) sol1.push_back(inp[i]);
            else sol2.push_back(inp[i]);
            nowl+=inp[i].cnt;
        }
    }
    //for(auto [i,j]:sol1) for(int x=1;x<=i;x++) cout <<j;
    //for(auto [i,j]:sol2) for(int x=1;x<=i;x++) cout <<j;
    reverse(sol2.begin(),sol2.end());
    long long ans=0,nowi=0,nowj=0;
    //cout <<sol1.size() <<' ' <<sol2.size() <<endl;
    while(nowi<sol1.size()&&nowj<sol2.size()){
        long long use=min(sol1[nowi].cnt,sol2[nowj].cnt);
        sol1[nowi].cnt-=use,sol2[nowj].cnt-=use;
        //cout <<sol1[nowi].cnt <<' ' <<sol2[nowj].cnt <<endl;
        if(sol1[nowi].cnt==sol2[nowj].cnt){
            if(sol1[nowi].val!=sol2[nowj].val) ans+=use;
            nowi++,nowj++;
        }else if(sol1[nowi].cnt==0){
            if(sol1[nowi].val!=sol2[nowj].val) ans+=use;
            nowi++;
        }else{
            if(sol1[nowi].val!=sol2[nowj].val) ans+=use;
            nowj++;
        }
    }
    cout <<ans <<endl;
    return 0;
}
