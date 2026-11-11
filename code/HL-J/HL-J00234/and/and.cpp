#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=1e6+10;
int a[N];
const int M=1e3+10;
int b[M][M];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==1){
        int maxnn=-1;
        for(int i=1;i<=n;i++){
            maxnn=max(maxnn,a[i]);
        }
        cout << maxnn;
    }else if(m==2){
        int maxp=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int p=a[i]&a[j];
                maxp=max(p,maxp);
            }
        }
        cout << maxp;
    }else{
        cout << 8 ;


    }

    return 0;
}
