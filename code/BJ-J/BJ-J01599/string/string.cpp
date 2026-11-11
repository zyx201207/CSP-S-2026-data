#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct aaa{
    char a;int x;
}f[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>f[i].x>>f[i].a;
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(f[l].x>f[r].x){
            if(f[l].a!=f[r].a) ans+=f[r].x;
            f[l].x-=f[r].x;
            r--;
        }else if(f[l].x<f[r].x){
            if(f[l].a!=f[r].a) ans+=f[l].x;
            f[r].x-=f[l].x;
            l++;
        }else{
            if(f[l].a!=f[r].a) ans+=f[l].x;
            r--;l++;
        }
    }cout<<ans;
    return 0;
}
