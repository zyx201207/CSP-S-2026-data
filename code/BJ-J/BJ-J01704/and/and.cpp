#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    int maxa,maxb;
    maxn=0;
    for(int j=1;j<=n;j++){
        for(int k=j+1;k<=n;k++){
            if((a[j]&a[k])>maxn){
                maxn=(a[j]&a[k]);
                maxa=j,maxb=k;
            }
        }
    }
    a[maxa]=a[maxb]=0;
    if(m==2){
        cout<<maxn;
        return 0;
    }
    int maxx=0;
    for(int i=1;i<=m-2;i++){
        for(int j=1;j<=n;j++){
            if((maxn&a[j])>maxx){
                maxx=(maxn&a[j]);
                maxa=j;
            }
        }
        maxn=maxx;
        maxx=0;
        a[maxa]=0;
    }
    cout<<maxn;
    
    return 0;
}