#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool tong = true;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c){
            cout << 1;
    }
    else{
        cout << 0 << 0 <<0 << 0;
        return 0;
    }
    int bt = b.size();
    int dt = d.size();
    for (int i = 0; i < bt-1; i ++){
        if(b[i] != d[i]){
                tong = false;
        cout << 0 <<0 <<0;
        return 0;
    }
    }
    cout << 1;
    if(b[2] == 'A'||b[2] == 'B'||b[2] == 'C'){
        if(d[2] != 'A'&&d[2] != 'B' && d[2] != 'C'){
            cout << 0 << 0;
            return 0;
        }
    }
    if(b[2] == 'D'||b[2] == 'E'||b[2] == 'F'){
        if(d[2] != 'D'&&d[2] != 'E' && d[2] != 'F'){
            cout << 0 << 0;
            return 0;
        }
    }
      cout << 1;
      if(b[2] == 'A'){
            if(d[2]!='B'){
        cout << 0;
        return 0;
            }
      }
      if(b[2] == 'B'){
            if(d[2]!='A'&&d[2]!='C'){
        cout << 0;
        return 0;
            }
      }
      if(b[2] == 'F'){
            if(d[2]!='E'){
        cout << 0;
        return 0;
            }
      }
      if(b[2] == 'C'){
            if(d[2]!='B'){
        cout << 0;
        return 0;
            }
      }
      if(b[2] == 'D'){
            if(d[2]!='E'){
        cout << 0;
        return 0;
            }
      }
      if(b[2] == 'E'){
            if(d[2]!='D'&&d[2]!='F'){
        cout << 0;
        return 0;
            }
      }
      cout << 1;
    return 0;
}
