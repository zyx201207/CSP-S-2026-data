#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
struct st{
    int st_num;
    int st_time;
};
ll c,n,m,d,q,k,ALL = 0;
int w[N],a[N];
vector<vector<st>> line;


int time(int x){
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            if(line[i][j].st_num==x) return line[i][j].st_time;
        }
    }
}

int lin(int x){
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            if(line[i][j].st_num==x) return i;
        }
    }
}

int p(int x){
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            if(line[i][j].st_num==x) return j;
        }
    }
}

bool check(int l,int r){
    int l_p,r_p;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            if(line[i][j].st_num==l) l_p = i;
            if(line[i][j].st_num==r) r_p = i;
        }
    }
    if(l_p==r_p){
        return true;
    }
}


int time1(int x,int y){

    for(int i = 1;i<=k;i++){
        if(line[y][i].st_num==x) return line[y][i].st_time;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(int i =1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>k;
        a[i] = k;
        for(int j = 1;j<=a[i];j++){
            cin>>line[i][j].st_num>>line[i][j].st_time;
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        int same;
        int l_l = lin(l),r_l = lin(r);
        for(int i = 1;i<=a[l_l];i++){
            for(int j = 1;j<=a[r_l];j++){
                if(line[l_l][i].st_num==line[r_l][j].st_num) same = line[l_l][i].st_num;
            }
        }
        if(check(l,r)){
            ALL=w[l]+w[r]+time(l)+time(r);
            cout<<ALL<<endl;
        }
        else{
            ll total =0;
            //ll dis1 = abs(p(l)-p(same)),dis2 = abs(p(r)-p(same));
            if(p(l)<p(same)){
                for(int i = p(l);i<=p(same);i++){
                    total+=time1(i,lin(l));
                }
            }
            else{
                for(int i = p(same);i<=p(l);i++){
                    total+=time1(i,lin(l));
                }
            }
            if(p(r)<p(same)){
                for(int i = p(r);i<=p(same);i++){
                    total+=time1(i,lin(r));
                }
            }
            else{
                for(int i = p(same);i<=p(r);i++){
                    total+=time1(i,lin(r));
                }
            }
            ALL = w[l]+w[r]+time(l)+time(r)+total;
        }
        cout<<ALL<<endl;
    }

    return 0;
}
