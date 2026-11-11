#include <bits/stdc++.h>
using namespace std;
const int N = 5e5,M = 3e5;
int a[N+5],b[M+5],c[M+5],d[M+5];
int n,m;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=i;j<=n;j++){
            if(d[a[j]]==0){
                c[++t]=a[j];
                d[a[j]]=t;
            }else{
                t = d[a[j]];
            }
        }
        for(int j=1;j<=t;j++){
            b[c[j]]++;
        }
        memset(d,0,sizeof(d));
    }
    for(int i=1;i<=m;i++){
        cout << b[i] << " ";
    }

    return 0;
}
