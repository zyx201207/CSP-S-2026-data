#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,op;
int a[500005],fl[500005];
long long t[500005][505],kz[500005],s[500005];
int c;
queue<long long> qu;
void find(){
    while(!qu.empty()){
        op = qu.first();
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(a[j][i] != 0 && fl[j] == 0){
                    qu.push(j);
                    fl[j] = 1;

                }
            }
        }
        qu.pop();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","r",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++{
        cin >> kz[i];
    }
    long long k;
    int aq,ti;
    for(int i = 1;i <= n;i++{
        cin >> k;
        for(int j = 1;j <= k;j++{
            cin >> aq >> ti;
            a[j]++;
            t[j][i] = t;
        }
    }
    int x,y;
    while(q--){
        cin >> x >> y;
        qu.push(x);
        find(x,y);
        cout << s[y] <<endl;

    return 0;
}
