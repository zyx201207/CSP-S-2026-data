#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
bool f(int s,int dx){
    for(int i = 0;i < s;i++){
        if(a[i] == dx) return 1;
    }
    return 0;
}
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m,t,d = 0,asiz,bsiz;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> t;
        a[i] = t;
    }
    asiz = n;
    bsiz = 0;
    while(asiz != 0){
        if(f(asiz,a[0]) == 1){
            for(int i = 0;i < bsiz;i++){
                b[i] = 0;
                bsiz = 1;
            }
        }
        b[d++] = a[0];
        bsiz++;
        for(int i = 0;i < n - 1;i++){
            a[i] = a[i + 1];
        }
        a[asiz--] = 0;
    }
    for(int i = 0;i < bsiz;i++){
        cout << b[i];
    }
    return 0;
}
