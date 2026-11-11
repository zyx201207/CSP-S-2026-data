#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n1,m1,n2,m2;
    cin >> n1>>m1>>n2>>m2;
    if(n1!=n2){
        cout << "0000" << endl;
        return 0;
    }
    else cout << 1;
    bool a = false;
    for(int i = 0;i < 2;i++) {
            if(m1[i] >= '0' && m1[i] <= '9' && m1[i] == m2[i]){
                a = true;
            }
    }
    if(a == false){
        cout << "000" << endl;
        return 0;
    }
    else cout << 1;
    a = false;
    bool b = false;
    if(m1[2] >= 'A' && m1[2] <= 'C' && m1[2] == m2[2]) a = true;
    else if((m1[2] == 'D' || m1[2] <= 'F')&& m1[2] == m2[2]) a = true;
    cout << (a ? 1: 0);
    if((m1[2] == 'A' || m1[2] == 'B') && m1[2] + 1 == m2[2]) b = true;
    if(m1[2] == 'D' && m1[2] + 2 == m2[2]) b = true;
    cout << (b?1:0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
