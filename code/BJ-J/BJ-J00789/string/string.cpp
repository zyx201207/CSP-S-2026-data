#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    char d;
    ll s;
}a[100010],nowa,nowb,b[100010];
ll n,now,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].d;
        b[n-i+1].s=a[i].s;
        b[n-i+1].d=a[i].d;
    }
    int i=1,j=1;
    while(i<=n||j<=n){
        if(nowa.s){
            if(nowa.d!=b[j].d) ans+=min(nowa.s,b[j].s);
            if(b[j].s>=nowa.s) b[i].s-=nowa.s,i++;
            else{
                nowa.s-=b[j].s;
                continue;
            }
        }
        if(nowb.s){
            if(nowb.d!=a[i].d) ans+=min(nowb.s,a[i].s);
            if(a[i].s>nowb.s) a[i].s-=nowb.s,j++;
            else{
                nowb.s-=a[i].s;
                continue;
            }
        }
        nowa.s=0;
        nowb.s=0;
        if(a[i].s>b[j].s) nowa.s=a[i].s-b[j].s,nowa.d=a[i].d;
        else nowb.s=b[j].s-a[i].s,nowb.d=b[j].d;
        if(a[i].d!=b[j].d) ans+=min(a[i].s,b[j].s);
    }
    cout<<ans/2<<endl;
    return 0;
}
