#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],r[300000],mx=0,ans;
int ar(int j,int o){
    if(o==m) return r[o]&r[o-1];
    for(int i=j;i<n-m+o;i++){
        r[o]=a[i];
        ans=r[o-1]&ar(i,o+1);
        return ans;
    }
    if(o==0)mx=max(mx,ans);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    ar(0,0);
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
