#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using ll = long long ;
struct abc{
    ll cnt;
    string s;
}a[N];
ll n,r=0,l=0,idl=0,idr=0,lenl=0,lenr=0,ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie (0);
    cout.tie(0);

    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin>>n;
    idr=n-1;//a shu zu zhong de di ji wei

    for(int i=0;i<n;i++){
        cin>>a[i].cnt>>a[i].s;
        r+=a[i].cnt;
    }
    lenl=a[idl].cnt,lenr=a[idr].cnt;

    while(idl<idr){
        ll leng=min(lenl,lenr);
        if(a[idl].s!=a[idr].s){
            ans+=leng;
        }
        lenl-=leng;
        lenr-=leng;
        if(lenl<=0){
            idl++;
            lenl=a[idl].cnt;
        }
        if(lenr<=0){

            idr--;
            lenr=a[idr].cnt;
        }
    }
    cout<<ans;

    return 0;
}
