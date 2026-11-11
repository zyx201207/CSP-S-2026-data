#include<bits/stdc++.h>
using namespace std;

char s[105] = {'G','F','D','C','B','A'};

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string src, srh, sxc, sxh;
    cin >> src >> srh >> sxc >> sxh;
    if (src != sxc){
        cout << 0 << 0 << 0 << 0;
    }
    else{
        cout << 1;
        int w1, w2;
        for (int i = 1; i <= 5; i++){
            if (srh[2] == s[i]){
                w1 = i;
            }
            if (sxh[2] == s[i]){
                w2 = i;
            }
        }
        if (srh[0] == sxh[0] && srh[1] == sxh[1]){
            cout << 1;
            if (abs(w1-w2) == 1 || w1 == 5 && w2 == 3 || w1 == 3 && w2 == 5){
                if (w1 == 3 && w2 == 2 || w1 == 2 && w2 == 3){
                    cout << 0;
                }
                else{
                    cout << 1;
                }
            }
            else{
                cout << "";
            }
        }
        else{
            cout << 0 << 0;
        }
        if (srh[0] == sxh[0] && srh[1] == sxh[1] && !(w1 == 3 && w2 == 2 || w1 == 2 && w2 == 3) && !(w1 == 3 && w2 == 5 || w1 == 5 && w2 == 3)){
            cout << 1;
        }
        else if (srh[2] == sxh[2]){
            if (srh[0] == sxh[0] && abs((srh[1]-'0')-(sxh[1]-'0')) == 1){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        else{
            cout << 0;
        }
    }

    return 0;
}
