#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,len,ans;
struct node{
    ll p;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].p>>a[i].c;
        len+=a[i].p;
    }
    ll i=1,j=n,tmpi=a[1].p,tmpj=a[n].p,lai,laj;
    while( i<=j ){
        if(i==j){
            ans+=min(lai,laj);
            break;
        }
        ll u=min(tmpi,tmpj);
        tmpi-=u;
        tmpj-=u;
        if(a[i].c!=a[j].c){
            ans+=u;
        }
        lai=tmpi;
        laj=tmpj;
        if(tmpi==0){
            i++;
            tmpi=a[i].p;
        }
        if(tmpj==0){
            j--;
            tmpj=a[j].p;
        }
    }
    cout<<ans;
    return 0;
}
