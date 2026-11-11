#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen(card.in,"r",stdin);
    freopen(card.out,"w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n]={0};
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n,cmp);
        cout<<a[0];
        return 0;
    }else if(m==n){
        int maxn=0;
        for(int i=0;i<n-1;i++){
            maxn=max(maxn,a[i]&a[i+1]);
        }
        cout<<maxn;
        return 0;
    }else if(m==2){
        int maxn=0;
    }
    return 0;
}
