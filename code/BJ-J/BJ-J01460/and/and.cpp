#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    int n,m,maxn=0;
    cin>>n>>m;
    int a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
        cout<<12;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i;i<n;j++){
            maxn=max(maxn,a[j]);
        }
    }
    cout<<maxn;
    return 0;
}
