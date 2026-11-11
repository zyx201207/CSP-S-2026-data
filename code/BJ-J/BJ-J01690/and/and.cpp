#include<iostream>
#include<cstdio>
using namespace std;
/*
int y[200001];
int e(int x){
    for(int i = 0;i >= 0;i++){
        y[i] = x % 2;
        x = x/2;
        if(y[i] == 1)break;
    }
    return 0;
}
*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,q,w= 0;
    cin >> n >> m;
    int a[n+1];
    int b[m+1];
    for(int i = 0;i <= n;i++){
        cin >>a[n];
    }
    for(int i = 0;i <= m;i++){
        for(int j = 0;j < n-1;j++){
            if(a[j+1] > a[j])b[q] = a[j+1];
            //cout /*<< "b:" */<< b[q] << endl;
        }
        q++;
    }
    w = b[0];
/*
    for(int i = 0;i <= m;i++){
        b[i] = e(b[i]);
    }
    cout << "Y:";
    for(int i = 100;i >= 0;i--){
        cout << y[i];
    }
    cout << endl;
*/
    for(int i = 0;i <= m;i++){
        w = w & b[i];
        //cout /*<< "a:" */<< w << endl;
    }
    cout << w;
    return 0;
}
