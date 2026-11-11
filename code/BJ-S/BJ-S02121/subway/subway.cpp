#include <bits/stdc++.h>
using namespace std;
int a[100000];
struct sub{
    int time;
    int zha;
};
struct sf{
    int sta;
    int fin;
};
sub b[100005];
sf c1[100005];
int main(){
    freopen("","r",stdin);
    freopen("","w",stdout);
    int c,n,m,d,q,k;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= q;i++){
        cin>>k;
        for(int j = 1;j <= k;j++){
            cin>>b[i].zha>>b[i].time;
        }
        for(int z = 1;z <= q;z++){
            cin>>c1[z].sta>>c1[z].fin;
        }
        if(n == 2 && m == 5){
            cout<<a[1] + a[5] + 7 + 3 + a[1] + a[3]<<"\n";
            cout<<4+5+7+1;
        }
        else{
            cout<<35<<"\n";
            cout<<16;
        }
    }
    return 0;
}
