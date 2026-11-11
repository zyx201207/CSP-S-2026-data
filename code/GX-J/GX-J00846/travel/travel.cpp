#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    int b;
    string x,y;
    cin >> a >> x >> b >> y;
    if(a == b){
        cout << 1;
        if(x[1] == y[1]){
            cout << 1;
            if((x[2] >= 'A'&&x[2] <= 'C')&&(y[2] >= 'A'&&y[2] <= 'C')){
                cout << 1;
            }
            else if((x[2] >= 'D'&&x[2] <= 'F')&&(y[2] >= 'D'&&y[2] <= 'F')){
                cout << 1;
                if(x[2] + 1==y[2]||y[2] + 1==x[2])
                cout << 1;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
