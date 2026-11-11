#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],c[300005],c2[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int q = 1;q <= n;q++){
        memset(c,0,(m<<2)+4);
        for(int i = q;i <= n;i++){
            int ai = a[i];
            if(c[ai]) for(int j = c[ai];j <= i-1;j++) c[a[j]] = 0;
            c[ai] = i;
        }
        for(int i = 1;i <= m;i++) if(c[i]) c2[i]++;
    }
    for(int i = 1;i <= m;i++) cout<<c2[i]<<" ";
    return 0;
}