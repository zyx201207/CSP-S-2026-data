#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500100],n,m,t[500100],mx,s,zb,f[500100];
int main(){
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int ti=m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        t[-3]=0;
        t[a[i]]++;
        if(t[a[i]]>=mx){
            mx=t[a[i]];s=a[i];
        }
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++){
        if(a[i]==s){
           zb=i;
           break;
        }
    }
    if(mx==1){
        zb=ceil(n/2);
    }
    for(ll i=0;i<n;i++){
        if(a[i]==s&&a[i+1]!=s&&a[i+1]-a[i]==1){
           zb=i+1;mx=t[a[i+1]];s=a[i+1];
        }
    }
    for(ll i=zb-1;i>=0;i--){
        if(ti==0){
            break;
        }
        int c=abs(a[zb]-a[i]);
        if(ti>=c){
            ti-=c;
            a[i]+=c;
            mx++;
        }
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
