#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int a[10005];
    for(int i = 1;i <= n;i++){cin >> a[i];}

    int b[10005];
    int num = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(a[i] == a[j]){num = a[i];}
            else{b[i] = a[j]-a[i];}
        }
    }
    for(int i = 1;i <= n*(n-1)/2;i++){
        if(num < b[i]){num = b[i];}
    }
    int c[10005];
    int len = 0;
    while(1){
        int cnt = c[1];
        for(int i = 1;i <= n;i++){
            c[i] = b[i]-a[i];
            if(c[i]>cnt){
                cnt = c[i];
            }
        }
        if(m-cnt >= 0){
            m-=cnt;
            len++;
        }
        else{break;}
        n--;
        for(int j = 2;j <= n;j++){
            c[j-1] = c[j];
        }
    }

    cout << len;

    return 0;
}
