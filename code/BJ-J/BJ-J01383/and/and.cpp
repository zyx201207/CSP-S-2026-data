#include<bits/stdc++.h>
using namespace std;
long long m,n;
int ma=0,ma1,x,y;
int a[200000],b[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ma=max(ma,(a[i]&a[j]));
            if(ma==(a[i]&a[j])){
                x=i;
                y=y;
            }
        }
    }
    a[x]=0;
    a[y]=0;
    sort(a,a+n);
    for(int i=0;i<=m-2;i++){
         ma1=ma;
        ma=ma&a[0];
        for(int j=0;j<n;j++){
            ma=max(ma,ma1&a[j]);
            if(ma==ma1&a[j]){
                x=j;
            }
        }
        a[x]=0;
        sort(a,a+n);
    }
    cout<<ma;
    return 0;
}
