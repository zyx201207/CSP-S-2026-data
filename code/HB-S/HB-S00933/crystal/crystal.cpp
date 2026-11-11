#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[5001];
long long y[5001][5001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-1;j++){
            y[i][j]=a[i]-a[j];
        }
    }
    int mn=INT_MIN;
    for(int i=1;i<=n;i++){
        long long s=0,v=0;
        for(int j=i;j>=1;j--){
            s+=y[i][j];
            if(s<=m) v++;
            else break;
        }
        if(v>=mn)mn=v;
    }
    cout<<mn;
    return 0;
}

