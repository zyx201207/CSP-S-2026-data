#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    long long a[10005],c[10005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        if(i-1==a[i-1]){
        for(int j=1;i<=i;j++){
            c[j]=a[j];
            a[j]=0;
        }
        }
        sort(a+1,a+n+1);
        if(a[i]==a[n]){
            a[1]=a[i];
        }

    }
    a[3]=a[1]+1;
    for(int i=1;i<=m;i++){
        cout<<a[i];
    }
    return 0;
}