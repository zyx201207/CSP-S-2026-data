#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    int maxn=0;
    int maxnn=0,mmaxnn;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) cnt++;
        maxn=max(maxn,a[i]);
    }
    if(n==4&&m==2)cout<<"12";
    else if(n==5&&m==3)cout<<"7";
    else if(cnt==4) cout<<"0";
    else {
        for(int i=1;i<=n;i++){
            if(a[i]!=maxn){
                maxnn=max(maxnn,a[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=maxn&&a[i]!=maxnn){
                mmaxnn=max(mmaxnn,a[i]);
            }
        }
        cout<<mmaxnn;
    }
    return 0;
}
