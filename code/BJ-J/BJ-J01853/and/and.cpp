#include<bits/stdc++.h>
using namespace std;
const int P = 1e6+25;
int n,m,v = 0;
int a[P];
int ans = -214748364;
int fin(int i,int ven,int val){
    //cout <<ven<<' ';
    if(ven == m){
        return val;
    }
    int add = -214748364;
    for(int j=i+1;j<=n;j++){
        add = max(add,fin(j,ven+1,a[j]));
    }
    //cout <<val<<' '<<add<<' '<<ven<<endl;
    if(add >= 0)val=val&add;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,fin(i,1,a[i]));
    }
    cout <<ans;
}
