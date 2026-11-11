#include <bits/stdc++.h>
using namespace std;
int zhaun(string x){
    int ans = 0;
    ans += (x[0]-'0')*10;
    ans += x[1] - '0';
    return ans;
    }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string xmc,xmd,xhc,xhd;
    cin >> xmc >> xmd >> xhc >> xhd;
    bool flag = true;
    int xxc,xdh;
    xxc=zhaun(xmc);
    xdh = zhaun(xhc);
    int cnmm = zhaun(xmd);
    int cnmh = zhaun(xhd);
    if(xdh != xxc){
        cout << "0000";
        flag = false;
    }else{
        cout << '1';
    }
    if(!flag){
        return 0;
    }
    if(cnmm != cnmh){
        cout <<"000";
        flag = false;
    }else{
        cout << '1';
    }
    char a = xmd[2];
    char d = xhd[2];
    if(!flag){
        return 0;
    }
    if(a== 'A' || a== 'B' || a=='C'){
        if(d == 'A' || d=='B' || d=='C'){
            cout <<'1';
        }else{
            flag = false;
            cout<<"00";
        }
    }else{
        if(d=='D' || d=='E'){
            cout <<'1';
        }else{
            flag = false;
            cout << "00";
        }
    }
    if(!flag){
        return 0;
    }else{
        if(a == 'A'){
            if(d == 'B'){
                cout << '1';
            }else{
                cout <<'0';
            }
        }else if(a=='E'){
            if(d == 'D'){
                cout<<'1';
            }else{
                cout<<'0';
            }
        }else if(a=='B'){
            if(d=='A' || d=='C'){
                cout << '1';
            }else{
                cout <<'0';
            }
        }else if(a=='C'){
            if(d=='B'){
                cout << '1';
            }else{
                cout <<'0';
            }
        }else{
            if(d=='E'){
                cout<<'1';
            }else{
                cout <<'0';
            }
        }
    }
    return 0;
}
