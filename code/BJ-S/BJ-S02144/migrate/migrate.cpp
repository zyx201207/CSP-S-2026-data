#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e7;
int n,d,c,t,a,cnt;
int x[N];
int b[N];

signed main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin >> c >>t;
    int b[t+1];
    for(int i=1;i<=t;i++){
        cin >> n >> d;
        for(int j=1;j<=n;j++){
            cin >> x[i];
            if(n%d==0){
                x[i]=n/d;
                x[i]/=2;
                }
            if(n%d!=0){
                x[i]=n/d;
                x[i]/=2;
                x[i]+=1;
                }
            }

        }
    for(int i=1;i<=t;i++){
        cout << x[i] <<endl;
    }


    return 0;
}
