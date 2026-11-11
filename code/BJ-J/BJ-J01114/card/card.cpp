#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt,b[N],ans,v[N];
int check(int x){
    int r=0;
    for(int i=1;i<=cnt;i++){
        if(b[i]==x) return i;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            cnt=1;
        memset(b,0,sizeof b);
        for(int j=i;j<=n;j++){
            int p=check(a[j]);
            if(p){
                cnt=p;
            }
            b[cnt]=a[j];
            //cout<<' '<<cnt<<' '<<a[j]<<' '<<j<<'\n';
            cnt++;
        }
        for(int j=1;j<cnt;j++){
                //cout<<b[j]<<' ';
            v[b[j]]++;
        }
       // cout<<'\n'<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<' ';
    }
   return 0;
}
