#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,l=0,r=0,qjdl=1,qjdr,ans=0;
struct node{
    LL num;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    qjdr=n;
    for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
    while(qjdl<qjdr){
        int tot=min(a[qjdl].num-l,a[qjdr].num-r);
        l+=tot;
        r+=tot;
        if(a[qjdl].c!=a[qjdr].c) ans+=tot;
        if(a[qjdl].num-l==0){
            l=0;
            qjdl++;
        }
        if(a[qjdr].num-r==0){
            r=0;
            qjdr--;
        }
    }
    cout<<ans;
    return 0;
}
