#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000100],b[1000100],l = 0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    if(m == 1){
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
    }
    if(m==2){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                b[l] = (i and j);
                l++;
            }
        }
        sort(b,b+n);
        cout<<b[l];
        return 0;
    }
    else if(m == n){
        int h=a[0];
        for(int i = 1;i < n;i++){
            h = (h and a[i]);
        }
        cout<<h;
        return 0;
    }
    else{
        sort(a,a+n);
        int o = (a[n] and a[n-1]);
        cout<<o;
        return 0;
    }

    return 0;
}
