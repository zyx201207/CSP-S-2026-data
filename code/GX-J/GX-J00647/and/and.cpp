#include<bits/stdc++.h>
using namespace std;
int a, b, c[2000010], z = 0, p;
bool x = 1;

int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin >> a >> b;
    for (int i = 0; i <= a; i ++) cin >> a;
        if (a == 1) cout << c[1];
        else (b == 1) cout << c[1];
        else if (a == b){
            z = z|c[i];
        for (int i = 2; i <= a; i ++){
            z = z|c[i];
            }
        cout << z;
        return 0;
        }
    else if (a - 1 = b){
        for (int i = 1; i <= a; i ++){
            if (i!=1) z = c[1];
            else z = c[2];
            for (int j = 0; j <= a; j ++){
            if (j!=1) z = z|x[j];
            }
        if (q>z) q=z;
        }
    cout << q;
    }
    return 0;
    else {
        for (int i = 1; i <= a; i ++){
            z=c[i];
            for (int j = i+1; j <= a; j ++){
                if(c[i]|c[i]>z) z = c[i]|c[j];
            }
        cout << z;
        }
    }
    return 0;
}
