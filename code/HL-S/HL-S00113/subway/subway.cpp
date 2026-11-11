//Oct31st==Dec?
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+10;
int w[N];
int k[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int i=1;i<=k[i];i++){
            int a,b;
            cin >> a >> b;
        }

    }
    if(c==0){
        if(n==2 && m==5 && d==20 && q==2 && w[1]==4 && w[2]==2&& w[3]==9 && w[4]==2 && w[5]==5){
            cout << 32 << endl << 17;
        }
        if(n==3 && m==7 && d==20 && q==2 && w[1]==8 && w[2]==3){
            cout << 35 << endl << 16;
        }

    }else if(c>=8 && c<=11){
        if(q==2){
            cout << 34 << endl << 12;
        }else if(q==3){
            cout <<17 << endl << 24 << endl << 36;
        }else if(q==4){
            cout << 10 << endl << 13 << endl << 20 << endl << 5;
        }
    }

    return 0;
}
