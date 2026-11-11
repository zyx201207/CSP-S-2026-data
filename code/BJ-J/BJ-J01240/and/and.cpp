#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m, a[10001];
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    if(m==n){
        int cnt=a[1];
        for(int i = 2 ; i <= n ; i++){
            cnt&=a[i];
        }
    cout << cnt
    }else if(m==1){
        int minn=0;
        for(int i = 1 ; i <= n ; i++){
            if(a[i]>minn) minn=a[i];
        }
        cout << minn;
    }else if(m==2){
        int maxn=0;
        for(int i = 1; i <= n ; i++){
            for(int j = i j <= n ; j++){
                if(a[i]&a[j]>maxn) maxn = a[i]&a[j];
            }
        }
        cout << maxn;
    }
    return 0;
}