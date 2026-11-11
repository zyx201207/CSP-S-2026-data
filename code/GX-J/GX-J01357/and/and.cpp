/*youdiannanxiang'a.
qidaoshujvyongjiaozaode.
woshihuixiesousuode,danshizaburangyunxingde,zhanbaolema.
*/
#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,m,s,a[99999];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s=max(s,a[i]);
    }
    if(m==1){
        cout<<s;
        return 0;
    }
    s=0;
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s=max(s,a[i]&a[j]);
            }
        }
        cout<<s;
        return 0;
    }
    if(m==n){
            s=a[0];
        for(int i=0;i<n;i++){
            s=s&a[i];
        }
    cout<<s;
    return 0;
    }
    sort(a+0,a+n);
    s=a[n-1];
    for(int i=0;i<m;i++){
        s=s&a[n-i-1];
    }
    cout<<s;
    return 0;
}
