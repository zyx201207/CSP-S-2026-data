#include<bits/stdc++.h>
using namespace std;

bool check1(const char &a,const char &b){
    return a == 'A' && b == 'B' || a == 'B' && b == 'A' || a == 'B' && b == 'C' || a == 'C' && b == 'B' || a == 'A' && b == 'C' || a == 'C' && b == 'A' || a == 'D' && b == 'F' || a == 'F' && b == 'D';
}
bool check2(const char &a,const char &b){
    return a == 'A' && b == 'B' || a == 'B' && b == 'C' || a == 'D' && b == 'F' || b == 'A' && a == 'B' || b == 'B' && a == 'C' || b == 'D' && a == 'F';
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string c1,c2,s1,s2;
    int r1 = 0,r2 = 0,r3 = 0,r4 = 0;
    cin >> c1 >> c2 >> s1 >> s2;
    if(c1 == s1){
        if(c2[0] == s2[0] && c2[1] == s2[1]){
            if(check1(c2[2],s2[2])){
                if(check2(c2[2],s2[2])){
                    r1 = 1;
                }
                r2 = 1;
            }
            r3 = 1;
        }
        r4 = 1;
    }
    cout << c1 << c2 << s1 << s2 << endl;
    cout << r4 << r3 << r2 << r1 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
