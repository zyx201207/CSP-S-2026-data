#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+5;
int n, m, a[N], b[N][35];
int len, k, ans;

void calc(int x){
    int c=0;
    b[x][0]=a[x];
    while(a[x]>0){
        b[x][++c]=a[x]%2;
        a[x]/=2;
    }
    len=max(len, c);
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1, greater<int>());
    for(int i=1;i<=n;i++)
        calc(i);
    for(int j=len;j>=1;j--){
        k=0; ans=(1<<30)-1;
        for(int i=1;i<=n;i++)
            if(b[i][j]==1){
                k++; ans&=b[i][0];
                if(k==m){
                    cout<<ans<<endl;
                    return 0;
                }
            }
    }
    cout<<0<<endl;
    return 0;
}