#include<iostream>
#include<string>
using namespace std;
int c1,c2,pai1,pai2;
string s1,s2;
char lie1,lie2;
bool flag1,flag2,flag3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    pai1 = 10 * (s1[0] - '0') + s1[1] - '0';
    pai2 = 10 * (s2[0] - '0') + s2[1] - '0';
    lie1 = s1[2];
    lie2 = s2[2];
    if (c1 == c2){
        cout << 1;
        flag1 = true;
    }
    else
        cout << 0;
    if (pai1 == pai2 && flag1){
        cout << 1;
        flag2 = true;
    }
    else
        cout << 0;
    if (lie1 <= 'C' && lie2 <= 'C' && flag2){
        cout << 1;
        flag3 = true;
    }
    else if (lie1 >= 'D' && lie2 >= 'D' && flag2){
        cout << 1;
        flag3 = true;
    }
    else
        cout << 0;
    if ((lie1 - lie2 == 1 || lie2 - lie1 == 1) && flag3)
        cout << 1;
    else
        cout << 0;
    return 0;
}
