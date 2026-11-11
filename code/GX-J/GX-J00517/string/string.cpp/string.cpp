#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int m[10005];
    if(n=1){
        cout << "0";
    }
    if(n=2){
       if(m[1]<=m[2]){
        cout<<m[1];
       }
       else{
        cout<<m[2];
       }
    }
    if(n = 3){
        if((m[1]+m[2])<=m[3]){
            cout <<m[1]+m[2];
        }
        else if((m[2]+m[3])<=m[1]){
            cout <<m[2]+m[3];
        }
        else if((m[1]+m[3])<=m[2]){
            cout <<m[1]+m[3];
        }
        else if((m[1]+m[2])>m[3]&&(m[1]+m[3])>m[2]&&(m[2]+m[3])>m[1]){
             if(m[3]>=m[2]>=m[1]||m[3]>=m[1]>=m[2]){
                cout<<m[3];
             }
             else if(m[2]>=m[3]>=m[1]||m[2]>=m[1]>=m[3]){
                cout<<m[2];
             }
             else if(m[1]>=m[2]>=m[3]||m[1]>=m[3]>=m[2]){
                cout<<m[1];
             }
        }
    }
    return 0;
}
