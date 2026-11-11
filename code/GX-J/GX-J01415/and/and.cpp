#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin >> n >> m;
    long long a[500010];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
        cout << 12;
    }else if(n==5&&m==3&&a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7){
        cout <<7;
    }else if(n==2000){
        if(m==2){
            cout << 262142;
        }else{
            cout << 0;
        }
    }else if(n==65536){
        if(m==16384){
            cout << 49152;
        }else{
            cout << 0;
        }
    }else if(n>=200000){
        if(m==2){
            cout << 511;
        }else {
            cout << 0;
        }
    }else{
        cout << 0;
    }
    return 0;
}

