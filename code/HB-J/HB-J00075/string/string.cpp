#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int s;char id;
}a[200005];
int n,idl=1,idr,cnt;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n--){
        int b;char c;
        cin >> b >> c;
        if(a[idr].id==c) a[idr].s+=b;
        else a[++idr]={b,c};
    }
    while(idl<idr){
        if(a[idl].s<a[idr].s){
            a[idr].s-=a[idl].s;
            if(a[idl].id!=a[idr].id)
                cnt+=a[idl].s;
            idl++;
        }
        if(a[idl].s>a[idr].s){
            a[idl].s-=a[idr].s;
            if(a[idl].id!=a[idr].id)
                cnt+=a[idr].s;
            idr--;
        }
        if(a[idl].s==a[idr].s){
            if(a[idl].id!=a[idr].id)
                cnt+=a[idr].s;
            idr--;idl++;
        }
    }
    cout << cnt;
    return 0;
}
