#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,siz,ans;
struct d{
    ll len;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        siz+=a[i].len;
    }
    ll id1=1,l1=1,r1=a[1].len;
    ll id2=n,l2=1,r2=a[n].len;
    while(id1<=id2){
        //cout<<id1<<' '<<id2<<endl;
        if(r1-l1<r2-l2){
            if(a[id1].c!=a[id2].c) ans+=r1-l1+1;
            l2+=(r1-l1+1);
            id1++;
            l1=1;
            r1=a[id1].len;
        }else if(r1-l1>r2-l2){
            if(a[id1].c!=a[id2].c) ans+=r2-l2+1;
            l1+=(r2-l2+1);
            id2--;
            l2=1;
            r2=a[id2].len;
        }else{
            if(a[id1].c!=a[id2].c) ans+=r2-l2+1;
            id1++;
            l1=1;
            r1=a[id1].len;
            id2--;
            l2=1;
            r2=a[id2].len;
        }
    }
    cout<<ans;
    return 0;
}
