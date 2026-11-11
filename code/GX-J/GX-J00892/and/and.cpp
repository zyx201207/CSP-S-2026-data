#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >>m;

    int maxn = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    if (m==2){
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int x = 0;
            x = a[i]&a[j];
            if(maxn<x){
                maxn = x;
            }
        }

    }}

    else if (m==1){
       for (int i=0;i<n;i++){
        if (a[i]>maxn){
            maxn = a[i];
        }
        else {maxn==maxn;}
    }
    }
    else {
        for (int i=0;i<n;i++){
           for (int j=i+1;j<=n;j++){
            maxn = max(a[i],a[j]);
           }
        }
    }
cout <<maxn;





    return 0;
}
