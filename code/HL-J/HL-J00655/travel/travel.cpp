#include<bits/stdc++.h>
using namespace std;
int a, b;
string c, d;
int i[4];
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if(a == b){
        i[0] = 1;
        if(c[0] == d[0] && c[1] == d[1]){
            i[1] = 1;
            if(int(c[3] - 'A') <= 3 && int(d[3] - 'A') <= 3 || int(c[3] - 'A') > 3 && int(d[3] - 'A') > 3){
                i[2] = 1;
                if(char(c[3]+ 1) == d[3] && c[3] != 'C' && d[3] != 'D' || char(c[3] + 1) == d[3] && c[3] != 'D' && d[3] != 'C'){
                    i[3] = 1;
                }
                else if(char(c[3] - 1) == d[3] && c[3] != 'C' && d[3] != 'D' || char(c[3]- 1) == d[3] && c[3] != 'D' && d[3] != 'C'){
                	i[3] = 1;
				}
                else i[3] = 0;
            }
            else{
                i[2] = 0, i[3] = 0;
                cout << i[0] << i[1] << i[2] << i[3];
                return 0;
            }
        }
        else{
            i[1] = 0, i[2] = 0, i[3] = 0;
            cout << i[0] << i[1] << i[2] << i[3];
            return 0;
        }
    }
    else{
        i[0] = 0, i[1] = 0, i[2] = 0, i[3] = 0;
        cout << i[0] << i[1] << i[2] << i[3];
        return 0;
    }
    cout << i[0] << i[1] << i[2] << i[3];
    return 0;
}
