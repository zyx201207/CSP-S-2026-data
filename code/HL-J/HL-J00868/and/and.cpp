#include <bits/stdc++.h>
using namespace std;
int n;

int m;
int a[2000010];
int maxx=-1;
int an;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i==1){
            an=a[i];
        }else{
            an&=a[i];
        }
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout << maxx;
        return 0;
    }
    if(m==n){
        cout << an;
        return 0;
    }
    maxx=-1;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    maxx=max(maxx,a[i]&a[j]);
                }
            }
        }
        cout <<maxx;
        return 0;
    }
    sort(a+1,a+n+1);
    cout << a[n-m+1];
    return 0;
}
