#include <bits/stdc++.h>
using namespace std;
string t= "ABCDF";
bool w(char a, char b){
    bool e = 0;
    for (int i = 0; i < 3; i++){
        int j = 0;
        if (j == 2) j+2;
        if (t[j]==a&&t[j+1]==b){
            e+=1;
        }
    }
}
bool u(char a, char b){
    bool e1 = 0;
    if (a==t[0]||a==t[1]||a==t[2]){
        if (b==t[0]||b==t[1]||b==t[2]){
            e1 = 1;
        }
    }
    else if (a==t[3]||a==t[4]){
        if (b==t[3]||b==t[4]){
            e1 = 1;
        }
    }
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1;
    string c2,s2;
    cin >> c1 >> c2 >> s1 >> s2;
    if (c1 == s1){
        cout << 1;
    }else cout << 0;
    int c = c2[0]*10 +c2[1];
    int s = s2[0]*10 + s2[1];
    char x = c2[2],y = s2[2];
    if (c == s){
        cout << 1;
        if (u(x,y) == 1){
            cout << 1;
        }else cout << 0;
        if (w(x,y) == 1){
            cout << 1;
        }else cout << 0;
    }else cout << 0;



    return 0;
}
