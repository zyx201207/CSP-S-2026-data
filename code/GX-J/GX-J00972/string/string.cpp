#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string l,r;
    long long hel=0,her=0;
    pair<long long,char>a[200010]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        if(i<=n/2){
            hel+=a[i].first;
            if(l[l.size()]!=a[i].second) l=l+a[i].second;
        }
        else if(i>n/2&&n%2==0||i>n/2+1&&n%2){
            her+=a[i].first;
            if(r[r.size()]!=a[i].second) r=a[i].second+r;
        }
    }
    if(l==r&&(hel==her||l.size()==1&&l[0]==a[n/2+n%2].second)) cout<<0;
    else cout<<max(hel,her);
    return 0;
}
