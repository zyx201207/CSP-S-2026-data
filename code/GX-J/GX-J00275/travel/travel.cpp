#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,ss1,ss2;
    string s1,s2;
    cin >> c1>>s1>>c2>>s2;
    ss1=s1[2]-64;
    ss2=s2[2]-64;
    if(c1==c2){cout << 1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){cout << 1;
            if((ss1<=3&&ss2<=3)||(ss1>3&&ss2>3)){cout <<1;
                if(ss1-ss2==1||ss2-ss1=1)cout << 1;
                else cout << 0;
            }
            else cout << 0 << 0;
        }
        else cout << 0 << 0 << 0;
    }
    else cout << 0 <<0 << 0 << 0;


    return 0;
}
