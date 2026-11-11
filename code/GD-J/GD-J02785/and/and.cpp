#include <bits/stdc++.h>
using namespace std;
int m,n;
int b[10000005];
char c[30][10000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> m >> n;
    cin >> b[1];
    int maxn=b[1];
    if(n==1){
    for(int i=2;i<=m;i++){
        cin >> b[i];
        if(b[i]>b[i-1]){}
        maxn = b[i];
    }
    cout << maxn;
    return 0;
    }
    if(m==n){
    for(int i=2;i<=m;i++){
        cin >> b[i];
        if(b[i]>b[i-1]){}

    }
    for(int i=1;i<=m;i++){

        while(b[i]!=1){
            c[30-a1][a] = b[i]%2;
            b[i]/2;
            a1+=1;
        }
        c[30-a1][a] = 1;
    }
    int cnt=0;
    for(int i=30;i>=1;i--){
            bool a2=1;
        for(int j=1;j<=m;i++){
            a2=a2 && c[30-i][j];

        }
        cnt+=pow(2,30-i)*a2;
        }
        cout << cnt;
    }
    return 0;
}
