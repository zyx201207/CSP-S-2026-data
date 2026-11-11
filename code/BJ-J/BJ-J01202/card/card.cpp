#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],c[N],cnt,co[N];
int f(int x){
    for(int i=1;i<=cnt;i++){
        if(c[i]==x) return i;
        if(c[i]==0) break;
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int fi=f(a[j]);
            if(fi){
                for(int i=fi;i<=n;i++) c[j]=0;
                cnt=fi-1;
            }
            c[++cnt]=a[j];
        }
        for(int k=1;k<=cnt;k++){
            co[c[k]]++;
        }
        memset(c,0,sizeof(c));
        cnt=0;
    }
    for(int i=1;i<=m;i++) cout<<co[i]<<" ";
    return 0;
}
