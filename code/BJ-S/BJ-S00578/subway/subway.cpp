#include<bits/stdc++.h>
using namespace std;
int w[500000];
struct stt{
    int a;
    int t;
};
struct pln{
    int s;
    int e;
};
vector<stt> s[500];
int k[500];
pln p[500000];
int ht(int s,int e){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int ipt1;
    int ipt2;
    cin >> c >> n >> m >> d >> q;
    for(int i = 0;i < m;i++){
        cin >> w[i];
    }
    for(int i = 0;i < n;i++){
        cin >> k[i];
        for(int j = 0;j < k[i];j++){
            cin >> ipt1 >> ipt2;
            s[i].push_back({ipt1,ipt2});
        }
    }
    for(int i = 0;i < q;i++){
        cin >> p[i].s >> p[i].e;
        cout << s[p[i].s].t + w[p[i].s] + w[p[i].e];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
