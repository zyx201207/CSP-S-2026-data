#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m;
struct se{
    int x,id;
}t[N];
int f[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        for(int l=i;l<=n;l++){
            f[a[l]]++;
            if(t[a[l]].x==0){
                t[a[l]].x++;
                t[a[l]].id=l;
            }else{
                int o=t[a[l]].id;
                for(int p=o;p<l;p++){
                    t[a[p]].x--;
                    f[a[p]]--;
                }
                t[a[l]].x++;
                t[a[l]].id=l;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    return 0;
}
