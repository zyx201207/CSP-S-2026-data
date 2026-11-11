#include<bits/stdc++.h>
using namespace std;
int k[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]>=maxn){
            maxn=k[i];
        }
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==2){
            maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(maxn<=(k[j]&k[i])){
                maxn=k[j]&k[i];
            }
        }
    }
    cout<<maxn;
    return 0;
    }
    if(m==n){
        maxn=k[1];
        for(int i=2;i<=n;i++){
            maxn=(maxn&k[i]);
        }
    cout<<maxn;
    return 0;
    }
    sort(k+1,k+n+1);
    cout<<k[n-m+1];
    return 0;
}