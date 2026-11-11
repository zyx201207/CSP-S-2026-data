#include <bits/stdc++.h>
using namespace std;
const int mx1=5E5+10;
const int mx2=510;
const int mx3=1E5;
struct subw{
    int ord,ti;
}w1[mx1];

struct runsub{
    int runord,con,tim;
}w2[mx2];

struct question{
    int st,en;
}qu[mx3];


int e[mx2][mx1];

int c,n,m,d,q,k;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w1[i].ti;
        w1[i].ord=i;
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>w2[i].con>>w2[i].tim;
            w2[i].runord=i;
            e[w2[i].runord][w2[i].con]=w2[i].tim;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>qu[i].st>>qu[i].en;

    }
    return 0;
}
